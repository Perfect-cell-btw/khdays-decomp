/* Ov004_ResetPartyMemberAndLayout -- open the logo confirm dialog, ov004 (byte-identical twin of an ov000 helper). Resets the input
 * (Session_GetLocalPlayerIndex), builds the prompt box (PartyMember_ResetWithKind) and shows it anchored to the
 * save work buffer (gGameState + 0xee0) via Ov004_RunTransientLayoutPass. */

#include "game/engine.h"

extern void Ov004_RunTransientLayoutPass(int, void *anchor);
extern char *gGameState;
void Ov004_ResetPartyMemberAndLayout(int arg) {
    Session_GetLocalPlayerIndex();
    PartyMember_ResetWithKind(0, 0, arg, 0);
    Ov004_RunTransientLayoutPass(0, gGameState + 0xee0);
}
