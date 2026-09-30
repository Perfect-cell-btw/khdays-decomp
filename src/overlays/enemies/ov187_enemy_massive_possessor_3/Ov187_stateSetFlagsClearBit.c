/* Set flags 0x86 in the high byte of the u16 at obj+0x60, clear bit0 of the byte
 * at (obj+0x388)->+8, then dispatch. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov187_PublishLandingPose(void);
struct lo_020cd144 { unsigned int f : 8; };
void Ov187_stateSetFlagsClearBit(int param_1) {
    int child = *(int *)(param_1 + 4);
    {
        unsigned short *p = (unsigned short *)(*(int *)child + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 0x86;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    ((struct lo_020cd144 *)(*(int *)(*(int *)child + 0x388) + 8))->f &= ~1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov187_PublishLandingPose);
}
