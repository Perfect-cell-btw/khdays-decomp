extern void func_ov022_0209fb60();
extern void Ov022_SetSlotClaim();
extern void *data_ov071_020b9a60;

void Ov071_initSharedObjSetReadyFlag(void)
{
    char *p = (char *)data_ov071_020b9a60;
    func_ov022_0209fb60(p, 1, 2);
    Ov022_SetSlotClaim(p, 1, 1);
    if (*(signed char *)(p + 0xF0D) != 0) {
        ((unsigned char *)p)[0xF0C] |= 1;
    }
}
