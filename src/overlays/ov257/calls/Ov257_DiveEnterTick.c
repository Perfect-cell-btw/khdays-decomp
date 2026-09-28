/* Target check of an ov257 state: the nearest target (020cab14) becomes +0x5c; without one
 * sub-state 2 is requested and the tick ends. Otherwise animation 4 plays, the +0x3d0 part plays
 * motion 3, reaction +0x408 (as a halfword) mode 2 fires at the +4 point and the tick hands over to
 * Ov257_DiveTick. */
extern int Ov107_FindNearestObject(int obj, int kind);
extern void Ov107_PostTagUpdate(int owner, int anim, int mode);
extern void Ov107_StartAnim(int part, int motion, int mode);
extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov257_DiveTick(int *node);

void Ov257_DiveEnterTick(int *node)
{
    int *state = (int *)node[1];

    state[0x18] = Ov107_FindNearestObject(*state, 0);
    if (state[0x18] == 0) {
        *(unsigned char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    Ov107_PostTagUpdate(*state, 4, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3d0), 3, 0);
    Ov107_BuildAndSendUpdate(state[0], (short)*(int *)(*state + 0x408), 2, (void *)state[1]);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov257_DiveTick);
}
