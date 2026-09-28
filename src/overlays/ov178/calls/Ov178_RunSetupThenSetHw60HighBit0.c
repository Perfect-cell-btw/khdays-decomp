extern void Ov107_MoveNodeAndRelayout();

void Ov178_RunSetupThenSetHw60HighBit0(int this_) {
    unsigned short *p = (unsigned short *)(this_ + 0x60);
    unsigned int h;
    Ov107_MoveNodeAndRelayout(this_);
    h = *p;
    *p = h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 1) << 0x18) >> 0x10);
}
