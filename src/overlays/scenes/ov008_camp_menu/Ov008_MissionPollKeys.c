/* Feeds the key state (the session's in a session, the local one otherwise) to the menu's input
 * handler. */

extern int Session_Exists(void);
extern int GetGlobalU16At6(void);
extern int func_01ff8138(void);
extern void Ov008_CountPlayersInMask(void *value);

void Ov008_MissionPollKeys(void)
{
    unsigned short value;

    if (Session_Exists() != 0) {
        value = GetGlobalU16At6();
    } else {
        value = func_01ff8138();
    }

    Ov008_CountPlayersInMask(&value);
}
