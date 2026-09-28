extern int Ov002_RunShutdownHook(void);
extern void func_ov002_0206373c(void);
extern void Ov002_ClearCharBlock(void);
extern int Session_GetLocalPlayerIndex(void);
extern char *data_ov002_0207f99c;

/* Confirms the pending mission once the fade is done, and records the caller's choice when the
 * current slot is the local player's. */
void Ov002_RecordMissionChoice(int choice) {
    char *self = data_ov002_0207f99c;
    if (Ov002_RunShutdownHook() != 0) {
        return;
    }
    func_ov002_0206373c();
    Ov002_ClearCharBlock();
    if (*(int *)(self + 4) == Session_GetLocalPlayerIndex()) {
        *(int *)(self + 0x28) = choice;
    }
}
