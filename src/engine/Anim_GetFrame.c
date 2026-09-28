extern int *Anim_GetChannelState();

int Anim_GetFrame(void) {
    int *p = Anim_GetChannelState();
    if (p == 0) return 0;
    return *p;
}
