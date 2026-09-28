/* Points the effect block's two animation sets at the character's two rig attachments. */

extern int data_ov067_020b7380;

void Ov067_InitTwoGlobalChannelSlots(int this_) {
    int *base = (int *)(data_ov067_020b7380 + 0x2c2c);
    base[0x45] = *(int *)(this_ + 0x263c) + 4;
    base[0xd5] = *(int *)(this_ + 0x2640) + 4;
}
