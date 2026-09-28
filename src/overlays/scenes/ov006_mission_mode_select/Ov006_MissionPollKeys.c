/* Ov006_MissionPollKeys -- Mission Mode: read the current key state and feed it to the Mission Mode input
 * handler. Uses the debug/replay key source (GetGlobalU16At6) when it is active
 * (Session_Exists), otherwise the real hardware keys. */
extern int  Session_Exists(void);
extern int  GetGlobalU16At6(void);
extern int  func_01ff8138(void);
extern int  Ov006_CountPlayersInMask(short *keys);

int Ov006_MissionPollKeys(void) {
    short keys;
    if (Session_Exists() != 0) {
        keys = (short)GetGlobalU16At6();
    } else {
        keys = (short)func_01ff8138();
    }
    return Ov006_CountPlayersInMask(&keys);
}
