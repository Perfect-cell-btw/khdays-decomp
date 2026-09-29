#include "game/ov008_camp_menu.h"
#include "game/engine.h"
/* Ov008_FireExitMessage -- fire the title-screen exit message 0x200d (dispatch when the input
 * object at ctx+0x4e8 is idle, else forward), run teardown Ov008_FreeSceneBuffers, and drop the
 * context pointer. */
extern void Ov008_FreeSceneBuffers(void);
#define MISSION_CONTEXT (data_ov008_02090f24.pContext)

void Ov008_FireExitMessage(void) {
    if (MISSION_CONTEXT->localMode != 0) {
        GameState_SetFlag(0x200d);
    } else {
        func_020235bc(0x200d);
    }
    Ov008_FreeSceneBuffers();
    data_ov008_02090f24.pContext = 0;
}
