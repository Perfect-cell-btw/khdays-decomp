/* Returns the current frame of an animation channel, or 0 when the channel is unbound. */

extern int *Anim_GetChannelState();

int Anim_GetFrame(unsigned short *r0, int r1) {
    int *p = Anim_GetChannelState(r0, r1);
    if (p == 0) return 0;
    return *p;
}
