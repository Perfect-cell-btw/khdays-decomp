extern int data_ov049_020b4d00;
extern void *Ov022_ActorSetState();

void *Ov049_StoreArgToGlobalSlot22AndForward(int this_, int arg1) {
    char *base = (char *)(data_ov049_020b4d00 + 0x2cfc);
    *(int *)(base + 0x118) = arg1;
    *(int *)(base + 0x11c) = 0;
    return Ov022_ActorSetState(this_, 0x22, base, 0);
}
