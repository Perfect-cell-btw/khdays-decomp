#pragma thumb on
/* Ov000_BackupWrite -- issue a save-backup WRITE command, ov000. Runs the CARD
 * backup transfer (CARDi_RequestStreamCommand, mode 8/0xa/2) and stashes its result code at
 * data_ov000_0205ac2c[+4]. */
extern void CARDi_RequestStreamCommand(void *, int, int, int, int, int, int, int, int);
extern int  CARD_GetResultCode(void);
extern char data_ov000_0205ac2c[];
void Ov000_BackupWrite(int a, void *buf, int size) {
    CARDi_RequestStreamCommand(buf, a, size, 0, 0, 0, 8, 0xa, 2);
    *(int *)(data_ov000_0205ac2c + 4) = CARD_GetResultCode();
}
