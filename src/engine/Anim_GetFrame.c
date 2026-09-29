/* Returns the current frame of an animation channel, or 0 when the channel is unbound. */

extern int *Anim_GetChannelState();

int Anim_GetFrame(char *pR0, int r1) {
    unsigned short *r0 = (unsigned short *)pR0;
    int *p = Anim_GetChannelState(r0, r1);
    if (p == 0) return 0;
    return *p;
}
