/* Sets up the first slot of the shared battle object: claims it in the battle module and marks it
 * ready when its enable byte is set. */

extern void func_ov022_0209fb60(int a, int b, int c);
extern void Ov022_SetSlotClaim(int a, int b, int c);
void Ov098_initFlagStateObj(int obj) {
    func_ov022_0209fb60(obj, 0, 1);
    Ov022_SetSlotClaim(obj, 0, 1);
    if (*(signed char *)(obj + 0xda9) != 0)
        *(unsigned char *)(obj + 0xda8) |= 1;
}
