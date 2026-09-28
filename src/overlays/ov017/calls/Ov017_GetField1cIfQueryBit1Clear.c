extern int GameState_GetField();

void *Ov017_GetField1cIfQueryBit1Clear(int this_) {
    unsigned int r = GameState_GetField(*(unsigned short *)(this_ + 0x14),
                                   *(unsigned char *)(this_ + 0x16));
    r = ((r & 0xfffe) << 0xf) >> 0x10;
    if (r & 1) return 0;
    return (void *)(this_ + 0x1c);
}
