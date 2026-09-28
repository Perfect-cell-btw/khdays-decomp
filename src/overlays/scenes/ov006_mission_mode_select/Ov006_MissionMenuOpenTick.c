#include "game/ov006_mission_mode_select.h"
/* Ov006_MissionMenuOpenTick -- Mission Mode: menu-open tick, returns the next scene state (0 = stay).
 * While the scene is locked out (obj+0x4e8) it drives the sound and waits for the intro
 * jingle latch at obj+0x49c to clear, then clears the pending transition at obj+0x2c.
 * Otherwise an unselectable entry sends it straight to Ov006_UpdateAndGetIdleHandler. Once no
 * transition is pending it commits the entry and advances to Ov006_UpdateSelectionConfirmationState. */
extern void Ov006_TickCardTransferScene(void);
extern int  Ov006_IsSceneState4(void);
extern void Ov006_MissionUpdateInputTransition(void);
extern void GameSession_SetSyncEnabled(int a);
extern void Ov006_UpdateAndGetIdleHandler(void);
extern void Ov006_UpdateSelectionConfirmationState(void);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

#define OBJ ((int *)data_ov006_020565e4.pContext)

void *Ov006_MissionMenuOpenTick(void) {
    void *next = 0;
    if (OBJ[0x13a] != 0) {
        int *obj;
        Ov006_TickCardTransferScene();
        obj = OBJ;
        if (obj[0x127] != 0) {
            return next;
        }
        obj[0xb] = (int)next;
    } else if (Ov006_IsSceneState4() == 0) {
        return (void *)Ov006_UpdateAndGetIdleHandler;
    }
    if (OBJ[0xb] == 0) {
        Ov006_MissionUpdateInputTransition();
        GameSession_SetSyncEnabled(0);
        next = (void *)Ov006_UpdateSelectionConfirmationState;
    }
    return next;
}
