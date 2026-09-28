/* Sets the player's frame step (0x10 when not positive). */

void AnmPlayer_SetFrameStep(int *p, int v) {
    if (v <= 0) v = 0x10;
    p[3] = v;
}
