extern int data_ov087_020b9be0;
extern void Ov087_BindRig();

void Ov087_InitGlobalChannelSlot(int this_) {
    int *base = (int *)(data_ov087_020b9be0 + 0x2cfc);
    base[0x43] = *(int *)(this_ + 0x2640) + 4;
    Ov087_BindRig(this_);
    base[0x48] = 0;
}
