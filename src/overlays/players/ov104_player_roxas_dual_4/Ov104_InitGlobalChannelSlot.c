extern int data_ov104_020bc2a0;
extern void Ov104_BindRig();

void Ov104_InitGlobalChannelSlot(int this_) {
    int *base = (int *)(data_ov104_020bc2a0 + 0x2cfc);
    base[0x43] = *(int *)(this_ + 0x2640) + 4;
    Ov104_BindRig(this_);
    base[0x48] = 0;
}
