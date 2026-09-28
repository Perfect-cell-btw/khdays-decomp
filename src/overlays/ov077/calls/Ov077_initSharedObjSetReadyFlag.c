extern void func_ov022_0209fb60(int a, int b, int c);
extern void Ov022_SetSlotClaim(int a, int b, int c);
extern int *data_ov077_020b9b80;
void Ov077_initSharedObjSetReadyFlag(void) {
    int obj = (int)data_ov077_020b9b80;
    func_ov022_0209fb60(obj, 1, 2);
    Ov022_SetSlotClaim(obj, 1, 1);
    if (*(signed char *)(obj + 0xf0d) != 0)
        *(unsigned char *)(obj + 0xf0c) |= 1;
}
