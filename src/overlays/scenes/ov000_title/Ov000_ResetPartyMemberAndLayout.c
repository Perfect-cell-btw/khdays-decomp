/* Ov000_ResetPartyMemberAndLayout -- open the logo confirm dialog, ov000. Resets the input
 * (Session_GetLocalPlayerIndex), builds the prompt box (PartyMember_ResetWithKind) and shows it anchored to the
 * save work buffer (gGameState + 0xee0) via Ov000_RunTransientLayoutPass. */

#include "game/engine.h"

extern void Ov000_RunTransientLayoutPass(int, void *anchor);
extern char *gGameState;
void Ov000_ResetPartyMemberAndLayout(int arg) {
    Session_GetLocalPlayerIndex();
    PartyMember_ResetWithKind(0, 0, arg, 0);
    Ov000_RunTransientLayoutPass(0, gGameState + 0xee0);
}
