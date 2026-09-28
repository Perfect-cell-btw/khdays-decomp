#include "game/ov008_camp_menu.h"
/* Ov008_MissionPushDisplayConfig -- push the current display config (mode 2) plus the live key
 * state to func_02031600. The scene object carries its key block at +0x42c: the raw key word
 * at +4 and its packed form at +8, which Ov008_CountPlayersInMask turns into the handler's key code.
 *
 * PROVENANCE: byte-identical twin of Ov006_MissionPushDisplayConfig -- same code, this overlay's own
 * globals, propagated mechanically and verified byte-exact.
 * The scene-identity phrasing that came with the twin source (Mission Mode / char select /
 * ov025 panel) is the REP's, NOT established for ov008, so it was removed rather than
 * carried over. What IS measured: ov008's own strings include UI/mlt/res.p2 (the same pack
 * ov006 loads) plus UI/cm/*.p2 and ba/ch/*, so resource detail naming those is sound; the
 * scene label is not. The offsets and logic below are this function's -- the code is
 * byte-identical to the rep.
 */
extern int  Ov008_CountPlayersInMask(short *keys);
extern void func_02031600(void *cfg);
#define MISSION_CONTEXT (data_ov008_02090f24.pContext)

struct Ov006KeyBlock {
    int f0;
    int raw;
    unsigned short packed;
};

struct Ov006DispCfg {
    int mode;
    int keycode;
    int rawkeys;
    unsigned short packed;
};

void Ov008_MissionPushDisplayConfig(void) {
    struct Ov006DispCfg cfg;
    int *obj = (int *)data_ov008_02090f24.pContext;
    struct Ov006KeyBlock *kb = (struct Ov006KeyBlock *)((char *)obj + 0x42c);
    cfg.mode = 2;
    cfg.rawkeys = kb->raw;
    cfg.packed = kb->packed;
    cfg.keycode = Ov008_CountPlayersInMask((short *)&kb->packed);
    func_02031600(&cfg);
}
