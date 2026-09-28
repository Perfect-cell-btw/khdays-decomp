extern int data_ov049_020b4d00;
extern void Ov049_BindRig();

void Ov049_InitGlobalChannelSlot(int this_) {
    int *base = (int *)(data_ov049_020b4d00 + 0x2cfc);
    base[0x43] = *(int *)(this_ + 0x2640) + 4;
    Ov049_BindRig(this_);
    base[0x48] = 0;
}
