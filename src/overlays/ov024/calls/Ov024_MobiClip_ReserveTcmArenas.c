/* Ov024_MobiClip_ReserveTcmArenas -- MobiClip: reserve the two fast-memory arenas out of ITCM and DTCM.
 *
 * Arena ids 3 and 4 are ITCM and DTCM. Both are pinned by the arithmetic here, not guessed:
 * OS_GetArenaHi(3) - 0x659c lands the code blob at 0x01ff9a64 (= 0x02000000 - 0x659c), which is
 * exactly where the port byte-verified it; and OS_GetDTCMAddress() + 0x4000 is the end of the
 * 16 KB DTCM, so `+ 0x4000 - OS_GetArenaLo(4)` is the free DTCM tail.
 *
 * CODE arena: carved off the TOP of ITCM, exactly Ov024_MobiClip_GetDecoderCodeSize() = 0x659c bytes -- the
 * decoder blob's length. Whatever already lived up there is copied into the .bss buffer at
 * data_ov024_02093a48+0xd8 first, so it can be handed back later; ITCM is borrowed, not owned.
 * DATA arena: the free DTCM tail, capped at Ov024_MobiClip_GetTableArenaSize() = 0x2580 -- exactly the three
 * tables it has to hold (0x2100 + 0x300 + 0x180). It asks for no more than it needs.
 *
 * Both clamps are a MIN whose argument is evaluated twice, hence each getter being called on
 * both sides of the compare. The first clamp is a no-op in practice: the value being clamped was
 * just set from that same getter. They are written out longhand rather than as MIN(x, f())
 * because the ROM reaches the two sides through different expressions -- see below.
 *
 * data_ov024_0209ba48 == data_ov024_02093a48 + 0x8000, and the ROM uses BOTH forms: the pooled
 * symbol for the first store and the compare, and `base + 0x8000` everywhere after. Keeping
 * `base` in a live local is what earns it r4 and keeps dtcmFree in r5; if base dies early, mwcc
 * recycles r4 for dtcmFree and falls back to pooling each address (4 B short, wrong tail).
 *
 * dtcmLo exists to pin the evaluation order: the ROM calls OS_GetArenaLo(4) BEFORE
 * OS_GetDTCMAddress(). Folded into one expression, mwcc evaluates left to right and calls them
 * the other way round.
 */
extern int Ov024_MobiClip_GetDecoderCodeSize(void);
extern int Ov024_MobiClip_GetTableArenaSize(void);
extern void Ov024_MobiClip_ArenaInitCode(unsigned int base, unsigned int size);
extern void Ov024_MobiClip_ArenaInitData(int base, unsigned int size);
extern void *OS_GetArenaHi(int id);
extern void *OS_GetArenaLo(int id);
extern void *OS_GetDTCMAddress(void);
extern void MIi_CpuCopy32(const void *src, void *dest, unsigned int size);
extern char data_ov024_02093a48[];
extern unsigned int data_ov024_0209ba48[];

void Ov024_MobiClip_ReserveTcmArenas(void) {
    char *base;
    unsigned int dtcmLo;
    unsigned int dtcmFree;

    base = data_ov024_02093a48;

    data_ov024_0209ba48[0x36] = Ov024_MobiClip_GetDecoderCodeSize();
    if (data_ov024_0209ba48[0x36] >= (unsigned int)Ov024_MobiClip_GetDecoderCodeSize()) {
        *(unsigned int *)(base + 0x80d8) = Ov024_MobiClip_GetDecoderCodeSize();
    }

    *(unsigned int *)(base + 0x80dc) =
        (unsigned int)OS_GetArenaHi(3) - *(unsigned int *)(base + 0x80d8);
    MIi_CpuCopy32((void *)*(unsigned int *)(base + 0x80dc), base + 0xd8,
                  *(unsigned int *)(base + 0x80d8));

    dtcmLo = (unsigned int)OS_GetArenaLo(4);
    dtcmFree = (unsigned int)OS_GetDTCMAddress() + 0x4000 - dtcmLo;
    if (dtcmFree >= (unsigned int)Ov024_MobiClip_GetTableArenaSize()) {
        dtcmFree = Ov024_MobiClip_GetTableArenaSize();
    }

    Ov024_MobiClip_ArenaInitCode(*(unsigned int *)(base + 0x80dc), *(unsigned int *)(base + 0x80d8));
    Ov024_MobiClip_ArenaInitData((int)OS_GetArenaLo(4), dtcmFree);
}
