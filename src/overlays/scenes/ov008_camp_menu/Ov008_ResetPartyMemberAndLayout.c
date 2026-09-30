/* Resets party member kind for the argument, then runs a transient layout pass. */

extern void Session_GetLocalPlayerIndex(int arg0);
extern void PartyMember_ResetWithKind(int arg0, int arg1, int arg2, int arg3);
extern char *gGameState;
extern void Ov008_RunTransientLayoutPass(int arg0, void *object);

void Ov008_ResetPartyMemberAndLayout(int arg0)
{
    Session_GetLocalPlayerIndex(arg0);
    PartyMember_ResetWithKind(0, 0, arg0, 0);
    Ov008_RunTransientLayoutPass(0, gGameState + 0xee0);
}
