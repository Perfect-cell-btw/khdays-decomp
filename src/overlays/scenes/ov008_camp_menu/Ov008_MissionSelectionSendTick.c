#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
#define CONTEXT (*(MissionContext **)&data_ov008_02090f24.pContext)
extern int Ov105_WM_SetEntry();
extern int Ov008_IsSceneState4(void);
extern void Ov008_RefreshSelectionSendBlock(void);
extern int Ov008_MissionIsTransitionDone(void);
extern int Ov008_SendPacket(const void *payload, u32 payloadSize);
extern void Ov008_MissionIdleStateNoOp(void);
extern void Ov008_MissionMenuOpenTick(void);

int Ov008_MissionSelectionSendTick(void)
{
    int zero = 0;
    int nextState = zero;

    if (CONTEXT->localMode != zero) {
        nextState = (int)Ov008_MissionMenuOpenTick;
        CONTEXT->sendBusy = zero;
    } else {
        if (!CONTEXT->message.selection.flags.bits.sendStarted) {
            if (Ov105_WM_SetEntry(zero, zero) == zero) {
                return nextState;
            }
        }
        if (Ov008_IsSceneState4() == zero) {
            return (int)Ov008_MissionIdleStateNoOp;
        }
        Ov008_RefreshSelectionSendBlock();
        CONTEXT->message.selection.flags.bits.sendStarted = 1;
        if (Ov008_MissionIsTransitionDone() != zero) {
            if (Ov008_SendPacket(
                    &CONTEXT->message.selection,
                    sizeof(MissionSelectionSendBlock)) != zero) {
                CONTEXT->entryUpdateMask = zero;
                nextState = (int)Ov008_MissionMenuOpenTick;
            }
        }
    }
    return nextState;
}
