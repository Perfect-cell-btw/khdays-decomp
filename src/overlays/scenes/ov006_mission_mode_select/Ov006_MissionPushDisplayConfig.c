#include "game/ov006_mission_mode_select.h"
#include "game/engine.h"
/* Ov006_MissionPushDisplayConfig -- Mission Mode: push the current display config (mode 2) plus the live key
 * state to Session_StoreSetup. The scene object carries its key block at +0x42c: the raw key word
 * at +4 and its packed form at +8, which Ov006_CountPlayersInMask turns into the handler's key code. */
extern int  Ov006_CountPlayersInMask(short *keys);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

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

void Ov006_MissionPushDisplayConfig(void) {
    struct Ov006DispCfg cfg;
    int *obj = (int *)data_ov006_020565e4.pContext;
    struct Ov006KeyBlock *kb = (struct Ov006KeyBlock *)((char *)obj + 0x42c);
    cfg.mode = 2;
    cfg.rawkeys = kb->raw;
    cfg.packed = kb->packed;
    cfg.keycode = Ov006_CountPlayersInMask((short *)&kb->packed);
    Session_StoreSetup(&cfg);
}
