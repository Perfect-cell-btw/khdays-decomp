/* Sets up this overlay's shared battle object: claims its slots in the battle module, then marks it
 * ready (bit 0 of +0xf0c) when its enable byte (+0xf0d) is set. */

extern void func_ov022_0209fb60(int a, int b, int c);
extern void Ov022_SetSlotClaim(int a, int b, int c);
extern int *data_ov102_020bb920;
void Ov102_initSharedObjSetReadyFlag(void) {
    int obj = (int)data_ov102_020bb920;
    func_ov022_0209fb60(obj, 1, 2);
    Ov022_SetSlotClaim(obj, 1, 1);
    if (*(signed char *)(obj + 0xf0d) != 0)
        *(unsigned char *)(obj + 0xf0c) |= 1;
}
