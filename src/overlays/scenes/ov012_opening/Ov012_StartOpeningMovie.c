/* Initializes the opening movie renderer and tilemaps, registers the frame callback, and opens the
 * requested stream in slot 1. If the stream fails to open it only sets flag 2 of the context:
 * Ov012_RunOpeningScene then never sets the movie state 3 and the scene script, waiting on
 * Ov012_MayWaitFrames, waits forever -- the game does not recover from a movie that fails to open. */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct MobiClipHeader {
    u16 destinationX;
    u16 destinationY;
    u16 macroblockWidth;
    u16 macroblockHeight;
    u16 tileBase;
    u16 palette;
    u16 flags;
    u16 cropLeft;
    u16 cropRight;
    u16 cropTop;
    u16 cropBottom;
} MobiClipHeader;

typedef struct MobiClipOpenRequest {
    char *stream0;
    char *stream1;
    char *stream2;
    void (*frameCallback)(void);
} MobiClipOpenRequest;

extern char *data_ov012_0205cb20;
extern void Ov012_UpdateOpeningGlobals(void);
extern void Ov012_InitOpeningRendererFromMobiClipHeader(void *renderer, int layer, void *font,
                                MobiClipHeader *header);
extern u16 *GetBGScreenBaseForLayer(int layer);
extern void Tilemap_FillRect(u16 *tilemap, int width, int height, int x, int y,
                          int mapWidth, u16 tile, int palette);
extern void Ov012_TileTextRenderer_SetReady(void *renderer, int ready);
extern void func_02031574(int value);
extern void func_02030e64(int value);
extern int Ov024_MobiClip_OpenStreams(MobiClipOpenRequest *request);

void Ov012_StartOpeningMovie(char *streamName)
{
    char *context;
    MobiClipOpenRequest request;
    MobiClipHeader header;

    context = data_ov012_0205cb20;
    request.stream0 = 0;
    request.stream1 = streamName;
    request.stream2 = 0;
    request.frameCallback = Ov012_UpdateOpeningGlobals;

    *(int *)(context + 0x8bdc) = 1;

    header.destinationX = 0;
    header.destinationY = 0x14;
    header.macroblockWidth = 0x20;
    header.macroblockHeight = 2;
    header.tileBase = 1;
    header.palette = 0xd;
    header.flags = 0;
    header.cropLeft = 0;
    header.cropRight = 0;
    header.cropTop = 3;
    header.cropBottom = 0;

    Ov012_InitOpeningRendererFromMobiClipHeader(context + 0x8b4c, 4, context + 0x8b40, &header);

    Tilemap_FillRect(GetBGScreenBaseForLayer(5),
                  header.macroblockWidth, header.macroblockHeight,
                  header.destinationX, header.destinationY,
                  0x20, header.tileBase, 0xe);
    Tilemap_FillRect(GetBGScreenBaseForLayer(6),
                  header.macroblockWidth, header.macroblockHeight,
                  header.destinationX, header.destinationY,
                  0x20, header.tileBase, 0xe);

    Ov012_TileTextRenderer_SetReady(context + 0x8b4c, 1);
    func_02031574(1);
    func_02030e64(1);

    if (Ov024_MobiClip_OpenStreams(&request) == 0) {
        *(u16 *)(context + 2) |= 2;
    }
}
