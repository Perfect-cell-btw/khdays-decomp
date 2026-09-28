/* Returns the number of players: in the session's member mask in a session, otherwise in the local
 * player mask. */

extern int Session_Exists(void);
extern unsigned short GetGlobalU16At6(void);
extern int func_01ff8138(void);
extern int Ov008_CountPlayersInMask(void *value);

int Ov008_CountPlayers(void)
{
    unsigned short value;

    if (Session_Exists() != 0) {
        value = GetGlobalU16At6();
    } else {
        value = func_01ff8138();
    }

    return Ov008_CountPlayersInMask(&value);
}
