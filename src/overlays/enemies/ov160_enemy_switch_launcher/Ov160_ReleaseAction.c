/* Release of the ov160 enemy's action: the +0x38 effect is stopped (ov022 ad8e0, 0) and
 * dropped, and the +4 / +8 / +0xc sub-objects are hidden (+0x5c bit 1). */
extern void Ov022_ToggleBit13ByMode(int effect, int a);

void Ov160_ReleaseAction(int *node)
{
    int *state = (int *)node[1];

    if (state[0xe] != 0) {
        Ov022_ToggleBit13ByMode(state[0xe], 0);
        state[0xe] = 0;
    }
    *(int *)(state[1] + 0x5c) |= 2;
    *(int *)(state[2] + 0x5c) |= 2;
    *(int *)(state[3] + 0x5c) |= 2;
}
