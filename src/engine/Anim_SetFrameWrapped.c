/* Sets an animation channel's frame, wrapping it once past the end of the animation; returns the
 * channel state. */

extern int *Anim_GetChannelState(int a0, int a1, int a2);

int *Anim_SetFrameWrapped(int arg0, int arg1, int arg2)
{
    int *p = Anim_GetChannelState(arg0, arg1, arg2);
    if (p != 0) {
        int lim;
        p[0] = arg2;
        lim = (int)(*(unsigned short *)(((int *)p[2]) + 1)) << 12;
        if (arg2 >= lim) {
            p[0] = arg2 - lim;
        }
    }
    return p;
}
