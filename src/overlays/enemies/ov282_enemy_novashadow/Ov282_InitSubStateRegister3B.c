/*
 * Ov282_InitSubStateRegister3B -- x3. AI-state entry: initialise the sub-state and register three handlers.
 * Clear *(u8)(state[0]+0x1c6)=0, set *(u8)(state[0]+0x1c7)=-1; cache anchor pointers state[1]=
 * state[0]+0xb0, state[2]=state[0]+0x74, state[3]=*(state[0]+0x384)+0xad, state[4]=0; set bits 0x6 in
 * the hi byte of the +0x60 hw flags. Then register handlers 1/0/2 via 0203c634(self, slot, cb) ->
 * 020d0b48, 020d07d0, 020d0a48.
 */
extern void SetIndexedSlot(int self, int idx, int cb);
extern void Ov282_AiLockAndPostUpdate(void);
extern void Ov282_AiDispatchAction(void);
extern void Ov282_AiApplyHeadingAndNormal(void);

void Ov282_InitSubStateRegister3B(int *self) {
    int *state = (int *)self[1];
    unsigned short *hw;
    unsigned int h;

    *(char *)(*state + 0x1c6) = 0;
    *(char *)(*state + 0x1c7) = -1;
    state[1] = *state + 0xb0;
    state[2] = *state + 0x74;
    state[3] = *(int *)(*state + 0x384) + 0xad;
    state[4] = 0;
    hw = (unsigned short *)(*state + 0x60);
    h = *hw;
    /* hw60.hi |= 6 -- explicit-shift form (bitfield |= adds a redundant mask) */
    *hw = h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 6) << 0x18) >> 0x10);
    SetIndexedSlot((int)self, 1, (int)&Ov282_AiLockAndPostUpdate);
    SetIndexedSlot((int)self, 0, (int)&Ov282_AiDispatchAction);
    SetIndexedSlot((int)self, 2, (int)&Ov282_AiApplyHeadingAndNormal);
}
