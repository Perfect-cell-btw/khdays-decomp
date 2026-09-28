extern int data_ov083_020b9b00;
extern void *Ov022_ActorSetState();

void *Ov083_StoreArgToGlobalSlotAndForward(int this_, int arg1) {
    char *base = (char *)(data_ov083_020b9b00 + 0x2df0);
    *(int *)(base + 0x114) = arg1;
    *(int *)(base + 0x118) = 0;
    return Ov022_ActorSetState(this_, 0x21, base, 0);
}
