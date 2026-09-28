/* Reset the two-word selection state to {0, 1}, then format setting 0x2080's
 * value (query kind 5) into the shared text buffer and close the dialog. */
extern int GameState_GetField(int id, int kind);
extern void OS_SPrintf(char *dst, const char *fmt, int value);
extern void SetGameMode(int a);

extern int data_0204c270[];
extern char data_0204c278[];
extern char data_ov002_0207efc8[];

void Ov002_ResetSelectionAndFormatValue(void) {
    data_0204c270[0] = 0;
    data_0204c270[1] = 1;
    OS_SPrintf(data_0204c278, data_ov002_0207efc8, GameState_GetField(0x2080, 5));
    SetGameMode(0);
}
