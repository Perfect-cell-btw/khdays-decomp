/* Marshals and claims actor slots 0 and 1, flagging each claimed one. */

extern void func_ov022_0209fb60();
extern void Ov022_SetSlotClaim();

void Ov088_ClaimBothSlots(char *p)
{
    func_ov022_0209fb60(p, 0, 1);
    Ov022_SetSlotClaim(p, 0, 1);
    if (*(signed char *)(p + 0xDA9) != 0) {
        ((unsigned char *)p)[0xDA8] |= 1;
    }
    func_ov022_0209fb60(p, 1, 2);
    Ov022_SetSlotClaim(p, 1, 1);
    if (*(signed char *)(p + 0xF0D) != 0) {
        ((unsigned char *)p)[0xF0C] |= 1;
    }
}
