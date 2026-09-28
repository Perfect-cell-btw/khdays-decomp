/* Stores arg1 into the global slot *globalData+0x2df0+0x114 and clears +0x118, then tail-calls a
 * handler(this, 0x21, slot, 0). */

extern int data_ov083_020b9b00;
extern void *Ov022_ActorSetState();

void *Ov083_StoreArgToGlobalSlotAndForward(int this_, int arg1) {
    char *base = (char *)(data_ov083_020b9b00 + 0x2df0);
    *(int *)(base + 0x114) = arg1;
    *(int *)(base + 0x118) = 0;
    return Ov022_ActorSetState(this_, 0x21, base, 0);
}
