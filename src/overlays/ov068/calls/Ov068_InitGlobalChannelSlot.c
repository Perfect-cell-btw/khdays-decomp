extern int data_ov068_020b7500;
extern void Ov068_BindRig();

void Ov068_InitGlobalChannelSlot(int this_) {
    int *base = (int *)(data_ov068_020b7500 + 0x2cfc);
    base[0x43] = *(int *)(this_ + 0x2640) + 4;
    Ov068_BindRig(this_);
    base[0x48] = 0;
}
