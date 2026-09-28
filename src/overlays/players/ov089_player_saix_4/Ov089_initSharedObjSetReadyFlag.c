/* Sets up this overlay's shared battle object: claims its slots in the battle module, then marks it
 * ready (bit 0 of +0xf0c) when its enable byte (+0xf0d) is set. */

extern void func_ov022_0209fb60();
extern void Ov022_SetSlotClaim();
extern void *data_ov089_020bc120;

void Ov089_initSharedObjSetReadyFlag(void)
{
    char *p = (char *)data_ov089_020bc120;
    func_ov022_0209fb60(p, 1, 2);
    Ov022_SetSlotClaim(p, 1, 1);
    if (*(signed char *)(p + 0xF0D) != 0) {
        ((unsigned char *)p)[0xF0C] |= 1;
    }
}
