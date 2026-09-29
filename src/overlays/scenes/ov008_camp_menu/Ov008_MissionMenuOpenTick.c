#include "game/ov008_camp_menu.h"
#include "game/engine.h"
/* Ov008_MissionMenuOpenTick -- menu-open tick, returns the next scene state (0 = stay).
 * While the scene is locked out (obj+0x4e8) it drives the sound and waits for the intro
 * jingle latch at obj+0x49c to clear, then clears the pending transition at obj+0x2c.
 * Otherwise an unselectable entry sends it straight to Ov008_MissionIdleStateNoOp. Once no
 * transition is pending it commits the entry and advances to Ov008_UpdateSelectionConfirmationState.
 *
 * PROVENANCE: byte-identical twin of Ov006_MissionMenuOpenTick -- same code, this overlay's own
 * globals, propagated mechanically and verified byte-exact.
 * The scene-identity phrasing that came with the twin source (Mission Mode / char select /
 * ov025 panel) is the REP's, NOT established for ov008, so it was removed rather than
 * carried over. What IS measured: ov008's own strings include UI/mlt/res.p2 (the same pack
 * ov006 loads) plus UI/cm/*.p2 and ba/ch/*, so resource detail naming those is sound; the
 * scene label is not. The offsets and logic below are this function's -- the code is
 * byte-identical to the rep.
 */
extern void Ov008_TickCardTransferScene(void);
extern int  Ov008_IsSceneState4(void);
extern void Ov008_MissionUpdateInputTransition(void);
extern void Ov008_MissionIdleStateNoOp(void);
extern void Ov008_UpdateSelectionConfirmationState(void);
#define MISSION_CONTEXT (data_ov008_02090f24.pContext)

#define OBJ ((int *)data_ov008_02090f24.pContext)

void *Ov008_MissionMenuOpenTick(void) {
    void *next = 0;
    if (OBJ[0x13a] != 0) {
        int *obj;
        Ov008_TickCardTransferScene();
        obj = OBJ;
        if (obj[0x127] != 0) {
            return next;
        }
        obj[0xb] = (int)next;
    } else if (Ov008_IsSceneState4() == 0) {
        return (void *)Ov008_MissionIdleStateNoOp;
    }
    if (OBJ[0xb] == 0) {
        Ov008_MissionUpdateInputTransition();
        GameSession_SetSyncEnabled(0);
        next = (void *)Ov008_UpdateSelectionConfirmationState;
    }
    return next;
}
