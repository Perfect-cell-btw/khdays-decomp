#pragma thumb on
/* Ov000_EmitCommandAndStoreHandle -- issue a save-backup READ command, ov000. Runs the CARD
 * backup transfer (CARDi_RequestStreamCommand, mode 6/1) and stashes its result code at
 * data_ov000_0205ac2c[+4]. */
extern void CARDi_RequestStreamCommand(int, void *, int, int, int, int, int, int, int);
extern int  CARD_GetResultCode(void);
extern char data_ov000_0205ac2c[];
void Ov000_EmitCommandAndStoreHandle(int a, void *buf, int size) {
    CARDi_RequestStreamCommand(a, buf, size, 0, 0, 0, 6, 1, 0);
    *(int *)(data_ov000_0205ac2c + 4) = CARD_GetResultCode();
}
