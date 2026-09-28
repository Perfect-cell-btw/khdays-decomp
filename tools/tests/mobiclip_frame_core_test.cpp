// Checks MobiClip_DecodeFrameCore (libs/mobiclip/video/portable) the way the game calls it: on
// the decoder state and planes the ARM payload works on. Build it for a 32-bit target, since the
// state is the ARM9's layout, e.g. from a Visual Studio x86 prompt:
//
//   cl /nologo /EHsc /O2 /I libs\mobiclip\video\portable tools\tests\mobiclip_frame_core_test.cpp
//      libs\mobiclip\video\portable\mobiclip_frame_core.cpp
//      libs\mobiclip\video\portable\mobiclip_reference.cpp
//
//   mobiclip_frame_core_test capture <capture-dir> <stem> <table0> <table1>
//       one DeSmuME capture from tools/mobiclip_capture.lua: the state and planes before the call,
//       compared with the state, planes and return value after it;
//   mobiclip_frame_core_test stream <mods> <ffmpeg-yuv> <table0> <table1> <frames>
//       a whole .mods video through six rotating plane buffers, compared frame by frame with
//       FFmpeg's planar output.
//
// The tables are the two run/level coefficient tables (8448 bytes each) the state points at.
#include "mobiclip_frame_core.h"

#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

typedef std::vector<unsigned char> Bytes;

static_assert(sizeof(void *) == 4, "build for a 32-bit target: the state is the ARM9's layout");
static_assert(sizeof(MobiClipDecoderState) == 0x454, "decoder state size");
static_assert(offsetof(MobiClipDecoderState, apLuma) == 0x0c, "luma planes");
static_assert(offsetof(MobiClipDecoderState, apChroma) == 0x24, "chroma planes");
static_assert(offsetof(MobiClipDecoderState, apCoefficientTables) == 0x3c, "tables");
static_assert(offsetof(MobiClipDecoderState, aQuantScan8x8) == 0x74, "quant/scan 8x8");
static_assert(offsetof(MobiClipDecoderState, aQuantScan4x4) == 0x174, "quant/scan 4x4");
static_assert(offsetof(MobiClipDecoderState, nQuantizer) == 0x3b4, "quantizer");
static_assert(offsetof(MobiClipDecoderState, bFormatVariant) == 0x48, "format bit");
static_assert(offsetof(MobiClipDecoderState, aMotion) == 0x3c4, "motion history");

static Bytes readFile(const std::string &path)
{
    std::ifstream input(path, std::ios::binary);
    if (!input)
        throw std::runtime_error("cannot open " + path);
    return Bytes(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>());
}

static unsigned int readU32(const Bytes &data, std::size_t offset)
{
    return data[offset] | (data[offset + 1] << 8) | (data[offset + 2] << 16) |
           ((unsigned int)data[offset + 3] << 24);
}

static std::string jsonNumber(const std::string &json, const std::string &key)
{
    std::size_t at = json.find("\"" + key + "\"");
    if (at == std::string::npos)
        throw std::runtime_error("manifest has no " + key);
    at = json.find(':', at) + 1;
    while (json[at] == ' ')
        ++at;
    std::size_t end = at;
    while (end < json.size() && json[end] >= '0' && json[end] <= '9')
        ++end;
    return json.substr(at, end - at);
}

static int checkCapture(const std::string &directory, const std::string &stem,
                        const Bytes &table0, const Bytes &table1)
{
    const std::string base = directory + "/" + stem;
    const Bytes manifestBytes = readFile(base + "_manifest.json");
    const std::string manifest(manifestBytes.begin(), manifestBytes.end());
    const int expectedReturn = std::stoi(jsonNumber(manifest, "decoderReturnBytes"));
    Bytes bitstream = readFile(base + "_bitstream.bin");
    const Bytes before = readFile(base + "_before_state.bin");
    const Bytes after = readFile(base + "_after_state.bin");
    if (before.size() != sizeof(MobiClipDecoderState) || after.size() != before.size())
        throw std::runtime_error("captured state is not 0x454 bytes");

    MobiClipDecoderState state;
    std::memcpy(&state, before.data(), sizeof state);
    Bytes luma[6], chroma[6];
    for (unsigned int i = 0; i < 6; ++i) {
        luma[i] = readFile(base + "_before_luma" + std::to_string(i) + ".bin");
        chroma[i] = readFile(base + "_before_chroma" + std::to_string(i) + ".bin");
        state.apLuma[i] = luma[i].data();
        state.apChroma[i] = chroma[i].data();
    }
    bitstream.resize(bitstream.size() + 64, 0);
    state.pBitstream = bitstream.data();
    state.apCoefficientTables[0] = table0.data();
    state.apCoefficientTables[1] = table1.data();

    const int returned = MobiClip_DecodeFrameCore(&state);

    const unsigned int tableAfter = readU32(after, 0x3b8);
    const unsigned char *expectedTable =
        tableAfter == readU32(before, 0x3c) ? table0.data() :
        tableAfter == readU32(before, 0x40) ? table1.data() : 0;
    bool historiesKept = true;
    for (unsigned int i = 1; i < 6; ++i) {
        historiesKept &= luma[i] == readFile(base + "_after_luma" + std::to_string(i) + ".bin");
        historiesKept &= chroma[i] == readFile(base + "_after_chroma" + std::to_string(i) + ".bin");
    }
    const bool checks[] = {
        returned == expectedReturn,
        luma[0] == readFile(base + "_after_luma0.bin"),
        chroma[0] == readFile(base + "_after_chroma0.bin"),
        historiesKept,
        state.nQuantizer == readU32(after, 0x3b4),
        state.bFormatVariant == readU32(after, 0x48),
        state.pCoefficientTable == expectedTable,
        std::memcmp(state.aQuantScan8x8, after.data() + 0x74, 0x140) == 0,
    };
    const char *names[] = {"return", "luma", "chroma", "histories", "quantizer", "format",
                           "table", "quantScan"};
    bool all = true;
    for (unsigned int i = 0; i < sizeof checks / sizeof checks[0]; ++i) {
        std::cout << names[i] << "=" << checks[i] << " ";
        all &= checks[i];
    }
    std::cout << "returned=" << returned << " expected=" << expectedReturn << "\n";
    return all ? 0 : 1;
}

static int checkStream(const std::string &modsPath, const std::string &yuvPath,
                       const Bytes &table0, const Bytes &table1, unsigned int frames)
{
    Bytes mods = readFile(modsPath);
    const Bytes expected = readFile(yuvPath);
    const unsigned int width = readU32(mods, 12);
    const unsigned int height = readU32(mods, 16);
    const unsigned int lumaSize = width * height;
    const unsigned int chromaSize = lumaSize / 4;
    const unsigned int frameSize = lumaSize + 2 * chromaSize;
    if (expected.size() < (std::size_t)frameSize * frames)
        throw std::runtime_error("the reference YUV is shorter than the frame count");
    mods.resize(mods.size() + 64, 0);

    unsigned int packet = 0x30;
    if (mods[4] == 'N' && mods[5] == '3') {
        for (;;) {
            const bool last = mods[packet] == 'H' && mods[packet + 1] == 'E';
            packet += 4 + (mods[packet + 2] | (mods[packet + 3] << 8)) * 4;
            if (last)
                break;
        }
    }

    // The owner's ring: six buffers of each plane, the frame being decoded in slot 0 and the
    // previous five after it, newest first.
    Bytes lumaRing[6], chromaRing[6];
    unsigned char *luma[6], *chroma[6];
    for (unsigned int i = 0; i < 6; ++i) {
        lumaRing[i].assign(MOBICLIP_PLANE_STRIDE * height, 0);
        chromaRing[i].assign(MOBICLIP_PLANE_STRIDE * height / 2, 0);
        luma[i] = lumaRing[i].data();
        chroma[i] = chromaRing[i].data();
    }
    MobiClipDecoderState state;
    std::memset(&state, 0, sizeof state);
    state.nWidth = width;
    state.nHeight = height;
    state.nQuantizer = 12;
    state.apCoefficientTables[0] = table0.data();
    state.apCoefficientTables[1] = table1.data();

    for (unsigned int frame = 0; frame < frames; ++frame) {
        const unsigned int packed = readU32(mods, packet);
        const unsigned int size = packed >> 14;
        unsigned char *oldestLuma = luma[5], *oldestChroma = chroma[5];
        for (unsigned int i = 5; i > 0; --i) {
            luma[i] = luma[i - 1];
            chroma[i] = chroma[i - 1];
        }
        luma[0] = oldestLuma;
        chroma[0] = oldestChroma;
        for (unsigned int i = 0; i < 6; ++i) {
            state.apLuma[i] = luma[i];
            state.apChroma[i] = chroma[i];
        }
        state.pBitstream = mods.data() + packet + 4;

        const int returned = MobiClip_DecodeFrameCore(&state);
        if (returned <= 0 || (unsigned int)returned > size + 2) {
            std::cerr << "frame " << frame << ": returned " << returned << " for a " << size
                      << "-byte packet\n";
            return 1;
        }
        const unsigned char *reference = expected.data() + (std::size_t)frame * frameSize;
        for (unsigned int y = 0; y < height; ++y) {
            if (std::memcmp(luma[0] + y * MOBICLIP_PLANE_STRIDE, reference + y * width, width)) {
                std::cerr << "frame " << frame << ": luma row " << y << " differs\n";
                return 1;
            }
        }
        // FFmpeg writes the second bitstream plane first.
        for (unsigned int y = 0; y < height / 2; ++y) {
            const unsigned char *row = chroma[0] + y * MOBICLIP_PLANE_STRIDE;
            if (std::memcmp(row + MOBICLIP_PLANE_STRIDE / 2,
                            reference + lumaSize + y * (width / 2), width / 2) ||
                std::memcmp(row, reference + lumaSize + chromaSize + y * (width / 2),
                            width / 2)) {
                std::cerr << "frame " << frame << ": chroma row " << y << " differs\n";
                return 1;
            }
        }
        packet += 4 + size;
    }
    std::cout << "frames=" << frames << " match\n";
    return 0;
}

int main(int argc, char **argv)
{
    try {
        if (argc == 6 && std::string(argv[1]) == "capture")
            return checkCapture(argv[2], argv[3], readFile(argv[4]), readFile(argv[5]));
        if (argc == 7 && std::string(argv[1]) == "stream")
            return checkStream(argv[2], argv[3], readFile(argv[4]), readFile(argv[5]),
                               (unsigned int)std::stoul(argv[6]));
    } catch (const std::exception &error) {
        std::cerr << error.what() << "\n";
        return 2;
    }
    std::cerr << "usage: mobiclip_frame_core_test capture <dir> <stem> <table0> <table1>\n"
                 "       mobiclip_frame_core_test stream <mods> <yuv> <table0> <table1> <frames>\n";
    return 2;
}
