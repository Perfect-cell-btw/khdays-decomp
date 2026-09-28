/* Recover entry of the ov144 enemy (and its byte-identical twin): with the previous sub-state
 * (+0x1c6) equal to 4 the actor plays animation 6 and hands off to the cd560 state; otherwise it
 * plays animation 1 (looped), reruns the +0x394 item's action 0 and hands off to cd5b8. */
extern void Ov107_PostTagUpdate(int actor, int anim, int flag);
extern void Ov107_StartAnim(void *item, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov144_ConfigSubStateThenAdvanceSlot(int *node);
extern void Ov144_AdvanceTick(int *node);

void Ov144_BeginRecover(int *node)
{
    int *state = (int *)node[1];

    if (*(signed char *)(*state + 0x1c6) == 4) {
        Ov107_PostTagUpdate(*state, 6, 0);
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov144_ConfigSubStateThenAdvanceSlot);
        return;
    }
    Ov107_PostTagUpdate(*state, 1, 1);
    Ov107_StartAnim(*(void **)(*state + 0x394), 0, 1);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov144_AdvanceTick);
}
