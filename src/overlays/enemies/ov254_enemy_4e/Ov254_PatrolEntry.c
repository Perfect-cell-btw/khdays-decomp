/* Move entry: bit 2 of the actor's +0x60 high byte is set, pose 0 plays (looping), the next
 * waypoint is chosen into +0x34 (020cd5f4) and copied to +0x30, the first tick runs at once and
 * the node moves to 020d1710. */
typedef unsigned short u16;

extern void Ov107_PostTagUpdate(int actor, int pose, int flag);
extern void Ov254_ChooseWaypoint(int *state, int a, int *out);
extern void Ov254_PatrolTick(int *node);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov254_PatrolEntry(int *node)
{
    int *state = (int *)node[1];

    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 4) << 0x18) >> 0x10);
    }
    Ov107_PostTagUpdate(*state, 0, 1);
    Ov254_ChooseWaypoint(state, 0, state + 0xd);
    state[0xc] = state[0xd];
    Ov254_PatrolTick(node);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov254_PatrolTick);
}
