/* Returns the state of an animation channel: the shared state when the animation drives all
 * channels (flag 4), else the channel's own entry. */

int Anim_GetChannelState(unsigned short *r0, int r1)
{
    if (*r0 & 4)
        return ((int *)r0)[0xd4 / 4];
    return ((int *)((char *)r0 + (r1 << 2)))[0xc / 4];
}
