/* Ov005_ResetPartyMemberAndLayout -- open the logo confirm dialog, ov005 (byte-identical twin of an ov000 helper). Resets the input
 * (Session_GetLocalPlayerIndex), builds the prompt box (PartyMember_ResetWithKind) and shows it anchored to the
 * save work buffer (data_0204be18 + 0xee0) via Ov005_RunTransientLayoutPass. */
extern void Session_GetLocalPlayerIndex(void);
extern void PartyMember_ResetWithKind(int, int, int, int);
extern void Ov005_RunTransientLayoutPass(int, void *anchor);
extern char *data_0204be18;
void Ov005_ResetPartyMemberAndLayout(int arg) {
    Session_GetLocalPlayerIndex();
    PartyMember_ResetWithKind(0, 0, arg, 0);
    Ov005_RunTransientLayoutPass(0, data_0204be18 + 0xee0);
}
