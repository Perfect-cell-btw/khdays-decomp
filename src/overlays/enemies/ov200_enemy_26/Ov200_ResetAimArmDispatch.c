/*
 * Ov200_ResetAimArmDispatch -- x3 (ov200/201/271). Reset the aim/attack state and (re)arm three dispatch
 * slots. Clear the mode byte *(*state+0x1c6)=0 and set the "dirty" byte *(*state+0x1c7)=-1; clear bit 0
 * of the low byte at *(*state+0x388)+8; cache the two rig pointers state[0x12]=*state+0xb0 and
 * state[0x13]=*state+0x74; set hw60.hi |= 6. Load the identity quaternion into state[0x21..0x24] and
 * mirror it to state[0x25..0x28]. Pick a random target between *(*state+0x224) and *(*state+0x228)
 * into state[0x20]. Finally arm dispatch slots 1, 0 and 2 with their handlers via 0203c634.
 */
struct b8 { unsigned f : 8; };
struct q4 { int w[4]; };

extern void Obj_SetFourWords(int *quat, int a, int b, int c, int e);
extern int RandNextScaled(int range);
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov200_stateSetFlagsClearBit(void);
extern void Ov200_AiDispatchAction(void);
extern void Ov200_AiSlerpHeading(void);

void Ov200_ResetAimArmDispatch(int self) {
    int *state = *(int **)(self + 4);
    unsigned short *hw;
    unsigned int h;
    int base, diff, r;

    *(unsigned char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    ((struct b8 *)(*(int *)(*state + 0x388) + 8))->f &= ~1;
    state[0x12] = *state + 0xb0;
    state[0x13] = *state + 0x74;
    hw = (unsigned short *)(*state + 0x60);
    h = *hw;
    *hw = h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 6) << 0x18) >> 0x10);
    Obj_SetFourWords(&state[0x21], 0, 0, 0, 0);
    *(struct q4 *)&state[0x25] = *(struct q4 *)&state[0x21];
    base = *(int *)(*state + 0x224);
    diff = *(int *)(*state + 0x228) - base;
    if (diff < 0) {
        diff = -diff;
    }
    r = RandNextScaled(diff + 1);
    state[0x20] = base + r;
    SetIndexedSlot(self, 1, &Ov200_stateSetFlagsClearBit);
    SetIndexedSlot(self, 0, &Ov200_AiDispatchAction);
    SetIndexedSlot(self, 2, &Ov200_AiSlerpHeading);
}
