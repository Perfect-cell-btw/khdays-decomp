extern unsigned short **Anim_GetChannelState(void);

int Anim_GetLengthQ12(void) {
    unsigned short **p;
    p = Anim_GetChannelState();
    if (!p) {
        return 0;
    }
    return p[2][2] << 12;
}
