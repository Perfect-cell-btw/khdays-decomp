struct flag8 {
    unsigned value : 8;
};

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov301_stateSetFlagsClearBit(void);
extern void Ov301_EnemyEnterSubState(void);
extern void Ov301_EnemyMoveTick(void);

void Ov301_InitStateSlots(int *node)
{
    int *state = (int *)node[1];

    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    ((struct flag8 *)(*(int *)(*state + 0x388) + 8))->value &= ~1;
    state[1] = *state + 0xb0;
    SetIndexedSlot(node, 1, Ov301_stateSetFlagsClearBit);
    SetIndexedSlot(node, 0, Ov301_EnemyEnterSubState);
    SetIndexedSlot(node, 2, Ov301_EnemyMoveTick);
}
