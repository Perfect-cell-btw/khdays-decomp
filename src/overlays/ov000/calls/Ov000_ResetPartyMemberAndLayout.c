/* Ov000_ResetPartyMemberAndLayout -- open the logo confirm dialog, ov000. Resets the input
 * (Session_GetLocalPlayerIndex), builds the prompt box (PartyMember_ResetWithKind) and shows it anchored to the
 * save work buffer (data_0204be18 + 0xee0) via Ov000_RunTransientLayoutPass. */
extern void Session_GetLocalPlayerIndex(void);
extern void PartyMember_ResetWithKind(int, int, int, int);
extern void Ov000_RunTransientLayoutPass(int, void *anchor);
extern char *data_0204be18;
void Ov000_ResetPartyMemberAndLayout(int arg) {
    Session_GetLocalPlayerIndex();
    PartyMember_ResetWithKind(0, 0, arg, 0);
    Ov000_RunTransientLayoutPass(0, data_0204be18 + 0xee0);
}
