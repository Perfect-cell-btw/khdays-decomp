/*
 * Game_ActionTurnHandler - two-phase action-slot handler; one of the two sentinels the action
 * system recognises by address (see Game_UnwindActionStack / Game_RunActionScript). param_1 is
 * the action-system state, param_2 an entity index -- not an angle, as this name once assumed:
 * the same two phases as Ov023_CmdActorSpeak.
 *
 * Phase one (param_2 >= 0): once the event block's resource (*(state+0x128)+0x28, handle at
 * +0xc) is ready (Obj_IsIdFree), it is handed to entity param_2 (TailForwardTrackEntry_2 ->
 * Actor_StartMotion) and the slot is re-queued with -param_2 (-0x63 standing for entity 0,
 * Slot48_StoreAtCurrentIndex); returns 0 (keep the slot). Phase two (negative): the entity's
 * texture image is dropped from main memory (EntityMgr_DropTextureImage) and it returns 1.
 *
 * THUMB. The index is signed (branch-if-negative selects phase two); the -0x63 sentinel is
 * built with mvns (~0x62); the two Slot48_StoreAtCurrentIndex calls share the return-0 tail.
 */

#include "game/engine.h"

extern void Slot48_StoreAtCurrentIndex(int param_1, int angle);

int Game_ActionTurnHandler(int param_1, int param_2)
{
    if (param_2 < 0) {
        if (param_2 == -0x63) {
            param_2 = 0;
        }
        EntityMgr_DropTextureImage(-param_2 & 0xffff);
        return 1;
    }
    if (Obj_IsIdFree(*(int *)(*(int *)(*(int *)(param_1 + 0x128) + 0x28) + 0xc)) != 0) {
        TailForwardTrackEntry_2(param_2 & 0xffff, *(int *)(*(int *)(param_1 + 0x128) + 0x28), 0, 0);
        if (param_2 == 0) {
            Slot48_StoreAtCurrentIndex(param_1, -0x63);
        } else {
            Slot48_StoreAtCurrentIndex(param_1, -param_2);
        }
    }
    return 0;
}
