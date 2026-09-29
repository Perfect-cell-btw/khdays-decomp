#include "game/ov006_mission_mode_select.h"
#include "game/engine.h"
/* Ov006_FireExitMessage -- fire the Mission Mode-screen exit message 0x200d (dispatch when the input
 * object at ctx+0x4e8 is idle, else forward), run teardown Ov006_FreeSceneBuffers, and drop the
 * context pointer. */
extern void Ov006_FreeSceneBuffers(void);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

void Ov006_FireExitMessage(void) {
    if (MISSION_CONTEXT->localMode != 0) {
        GameState_SetFlag(0x200d);
    } else {
        func_020235bc(0x200d);
    }
    Ov006_FreeSceneBuffers();
    data_ov006_020565e4.pContext = (void *)(0);
}
