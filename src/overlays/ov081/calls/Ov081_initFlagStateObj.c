extern void func_ov022_0209fb60(int a, int b, int c);
extern void Ov022_SetSlotClaim(int a, int b, int c);
void Ov081_initFlagStateObj(int obj) {
    func_ov022_0209fb60(obj, 0, 1);
    Ov022_SetSlotClaim(obj, 0, 1);
    if (*(signed char *)(obj + 0xda9) != 0)
        *(unsigned char *)(obj + 0xda8) |= 1;
}
