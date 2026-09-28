extern void Ov297_AcquireTargetGapAndAngle(void *node);

void Ov297_TickTimerOrEnterSubState2(int *node) {
    int *state = (int *)node[1];

    Ov297_AcquireTargetGapAndAngle(node);

    if (state[0x17] >= 0) {
        state[0x23] = 1;
        state[0x17] -= *(int *)(*node + 0x2c);
        return;
    }

    state[0x23] = 0;
    *(unsigned char *)(*state + 0x1c7) = 2;
}
