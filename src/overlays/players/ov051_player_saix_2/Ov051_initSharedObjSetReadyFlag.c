extern void func_ov022_0209fb60();
extern void Ov022_SetSlotClaim();
extern void *data_ov051_020b7380;

void Ov051_initSharedObjSetReadyFlag(void)
{
    char *p = (char *)data_ov051_020b7380;
    func_ov022_0209fb60(p, 1, 2);
    Ov022_SetSlotClaim(p, 1, 1);
    if (*(signed char *)(p + 0xF0D) != 0) {
        ((unsigned char *)p)[0xF0C] |= 1;
    }
}
