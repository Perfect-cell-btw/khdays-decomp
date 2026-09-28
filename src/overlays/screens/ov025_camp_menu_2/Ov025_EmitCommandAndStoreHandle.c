extern void CARDi_RequestStreamCommand();
extern int CARD_GetResultCode();
extern int data_ov025_020b5760;

void Ov025_EmitCommandAndStoreHandle(unsigned int arg0, unsigned int arg1, unsigned int arg2) {
    CARDi_RequestStreamCommand(arg0, arg1, arg2, 0, 0, 0, 6, 1, 0);
    *(int *)((char *)&data_ov025_020b5760 + 4) = CARD_GetResultCode();
}
