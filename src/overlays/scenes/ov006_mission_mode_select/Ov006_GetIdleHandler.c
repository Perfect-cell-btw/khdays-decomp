#include "game/ov006_mission_mode_select.h"
/* Ov006_GetIdleHandler -- advance the Mission Mode input state (Ov006_TickCardTransferScene), then return the
 * "idle" handler Ov006_IdleHandlerNoOp if the busy field (ctx+0x49c) is clear, else 0. */
extern void Ov006_TickCardTransferScene(void);
extern void Ov006_IdleHandlerNoOp(void);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

int Ov006_GetIdleHandler(void) {
    int result = 0;
    Ov006_TickCardTransferScene();
    if (MISSION_CONTEXT->busy == 0) {
        result = (int)Ov006_IdleHandlerNoOp;
    }
    return result;
}
