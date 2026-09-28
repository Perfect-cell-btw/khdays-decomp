extern void Ov259_Helper_Release(int param_1);

void Ov259_Helper_ReleaseIfReady(int this_) {
    if (*(int *)(this_ + 0x50) == 1) {
        unsigned short *p = (unsigned short *)(this_ + 0x60);
        unsigned int h = *p;
        *p = h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 2) << 0x18) >> 0x10);
        Ov259_Helper_Release(*(int *)(this_ + 0x214));
    }
}
