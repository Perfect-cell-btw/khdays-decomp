/* Returns the length of an animation channel's animation in fx32 frames, or 0 when the channel is
 * unbound. */

extern unsigned short **Anim_GetChannelState(unsigned short *, int);

int Anim_GetLengthQ12(unsigned short *r0, int r1) {
    unsigned short **p;
    p = Anim_GetChannelState(r0, r1);
    if (!p) {
        return 0;
    }
    return p[2][2] << 12;
}
