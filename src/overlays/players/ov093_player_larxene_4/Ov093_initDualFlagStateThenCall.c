/* Sets up both slots of this overlay's shared battle object (claims in the battle module, ready
 * bits when enabled), then builds its peer group. */

extern void func_ov022_0209fb60(int a, int b, int c);
extern void Ov022_SetSlotClaim(int a, int b, int c);
extern void Ov093_BuildPeerGroup(int a);
extern int *data_ov093_020bc3c0;
void Ov093_initDualFlagStateThenCall(void) {
    int obj = (int)data_ov093_020bc3c0;
    func_ov022_0209fb60(obj, 0, 1);
    Ov022_SetSlotClaim(obj, 0, 1);
    if (*(signed char *)(obj + 0xda9) != 0)
        *(unsigned char *)(obj + 0xda8) |= 1;
    func_ov022_0209fb60(obj, 1, 2);
    Ov022_SetSlotClaim(obj, 1, 1);
    if (*(signed char *)(obj + 0xf0d) != 0)
        *(unsigned char *)(obj + 0xf0c) |= 1;
    Ov093_BuildPeerGroup(obj);
}
