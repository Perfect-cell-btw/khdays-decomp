#include "nitro/types.h"

#include "game/ov006_mission_mode_select.h"

/* Sends the mission selection to the peers: sets the wireless entry, refreshes the send block and
 * sends it once the transition is done; returns the next state. */

#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
#define CONTEXT (*(MissionContext **)&data_ov006_020565e4.pContext)
extern int Ov105_WM_SetEntry();
extern int Ov006_IsSceneState4(void);
extern void Ov006_RefreshSelectionSendBlock(void);
extern int Ov006_MissionIsTransitionDone(void);
extern int Ov006_SendNetworkPacket(const void *payload, u32 payloadSize);
extern void Ov006_UpdateAndGetIdleHandler(void);
extern void Ov006_MissionMenuOpenTick(void);

int Ov006_MissionSelectionSendTick(void)
{
    int zero = 0;
    int nextState = zero;

    if (CONTEXT->localMode != zero) {
        nextState = (int)Ov006_MissionMenuOpenTick;
        CONTEXT->sendBusy = zero;
    } else {
        if (!CONTEXT->message.selection.flags.bits.sendStarted) {
            if (Ov105_WM_SetEntry(zero, zero) == zero) {
                return nextState;
            }
        }
        if (Ov006_IsSceneState4() == zero) {
            return (int)Ov006_UpdateAndGetIdleHandler;
        }
        Ov006_RefreshSelectionSendBlock();
        CONTEXT->message.selection.flags.bits.sendStarted = 1;
        if (Ov006_MissionIsTransitionDone() != zero) {
            if (Ov006_SendNetworkPacket(
                    &CONTEXT->message.selection,
                    sizeof(MissionSelectionSendBlock)) != zero) {
                CONTEXT->entryUpdateMask = zero;
                nextState = (int)Ov006_MissionMenuOpenTick;
            }
        }
    }
    return nextState;
}
