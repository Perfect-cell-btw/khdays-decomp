/* Ov025_ScrollList_Leave -- Ov025_ScrollList_Leave: clear game fields 0x35c5 (8 bits), 0x35d5
 * (10 bits), 0x35cd and 0x35df (8 bits each; GameState_SetField 020235e8) and leave the page:
 * when the context object (02084dd8) is 1 the menu is left entirely (ov002 0206d970 with
 * payload 0) and the target slot becomes -1 / -1 (02084798), otherwise 0 / -1; the cancel sound
 * plays (02033b78 0 / 3). */

#include "nitro/types.h"

extern void  GameState_SetField(int nField, int nBits, int nValue);      /* GameState_SetField */
extern int   Ov025_GetCtxObject95c0(void);                             /* Ov008_GetCtxObject95c0 */
extern void  Ov002_PostResultReport(int nPayload);
extern void  Ov025_SetTargetSlot(int nEntry, int nTarget);          /* Ov008_SetTargetSlot */
extern void  PlaySound(int nKind, int nSound);                  /* PlaySound */

void Ov025_ScrollList_Leave(void)
{
    GameState_SetField(0x35c5, 8, 0);
    GameState_SetField(0x35d5, 10, 0);
    GameState_SetField(0x35cd, 8, 0);
    GameState_SetField(0x35df, 8, 0);
    if (Ov025_GetCtxObject95c0() == 1) {
        Ov002_PostResultReport(0);
        Ov025_SetTargetSlot(-1, -1);
    } else {
        Ov025_SetTargetSlot(0, -1);
    }
    PlaySound(0, 3);
}
