/* Returns the number of players: in the session's member mask in a session, otherwise in the local
 * player mask. */

extern int  Session_Exists(void);
extern unsigned short  GetGlobalU16At6(void);
extern int  func_01ff8138(void);
extern int  Ov006_CountPlayersInMask(short *keys);

int Ov006_CountPlayers(void) {
    short keys;
    if (Session_Exists() != 0) {
        keys = (short)GetGlobalU16At6();
    } else {
        keys = (short)func_01ff8138();
    }
    return Ov006_CountPlayersInMask(&keys);
}
