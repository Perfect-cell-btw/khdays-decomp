/* Stores arg1 into the global slot *globalData+0x2cfc+0x118 and clears +0x11c, then tail-calls
 * Ov022_ActorSetState(this, 0x22, slot, 0). */

extern int data_ov068_020b7500;
extern void *Ov022_ActorSetState();

void *Ov068_StoreArgToGlobalSlot22AndForward(int this_, int arg1) {
    char *base = (char *)(data_ov068_020b7500 + 0x2cfc);
    *(int *)(base + 0x118) = arg1;
    *(int *)(base + 0x11c) = 0;
    return Ov022_ActorSetState(this_, 0x22, base, 0);
}
