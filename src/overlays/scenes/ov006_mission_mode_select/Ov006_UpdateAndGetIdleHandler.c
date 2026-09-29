#include "game/ov006_mission_mode_select.h"
#include "game/engine.h"
/* Ov006_UpdateAndGetIdleHandler -- if the shared flag is set run ReleaseServiceInstance, advance Mission Mode input
 * (Ov006_TickCardTransferScene), then return the idle handler Ov006_IdleStateNoOp when ctx+0x49c is
 * clear, else 0. */
extern void Ov006_TickCardTransferScene(void);
extern void Ov006_IdleStateNoOp(void);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

int Ov006_UpdateAndGetIdleHandler(void) {
    int result = 0;
    if (Session_Exists() != 0) {
        ReleaseServiceInstance();
    }
    Ov006_TickCardTransferScene();
    if (MISSION_CONTEXT->busy == 0) {
        result = (int)Ov006_IdleStateNoOp;
    }
    return result;
}
