/* Timed sound cue of an ov238 node: once +0x20 reaches `ticks` frames and the +0x31 cue counter is at
 * `cue`, the counter steps down and sound 0x12e/`variant` plays at the +8 point. */
extern void Ov107_BuildAndSendUpdate(int actor, int bank, int variant, void *at);

void Ov238_TimedCue(int *node, int ticks, int cue, int variant)
{
    int *state = (int *)node[1];

    if (state[8] < ticks * 0x88) {
        return;
    }
    if (*((unsigned char *)state + 0x31) != cue) {
        return;
    }
    *((unsigned char *)state + 0x31) -= 1;
    Ov107_BuildAndSendUpdate(*state, 0x12e, variant, (void *)state[2]);
}
