/* Attack tick of the ov221 enemy. The +0x5c timer accumulates the owner's rate. Once (+0x75)
 * past 0x770 with a +0x78 target or past 0x1a90 without, reaction 0x12a mode 0x13 fires at
 * the +8 point. Between 0x1540 and 0x2178 with a target, or between 0x2200 and 0x2ec0
 * without, the sub-action 7 runs (Ov221_StrikeSweepEntities). Once the +4 item goes idle (+0xad)
 * sub-state 2 is requested and the state ends. */
extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void Ov221_StrikeSweepEntities(int *state, int action, int arg);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov221_AttackTick(int *node)
{
    int *state = (int *)node[1];

    state[0x17] += *(int *)(node[0] + 0x2c);
    if (*(unsigned char *)((char *)state + 0x75) == 0
        && ((state[0x1e] != 0 && state[0x17] >= 0x770) || (state[0x1e] == 0 && state[0x17] >= 0x1a90))) {
        *(unsigned char *)((char *)state + 0x75) = 1;
        Ov107_BuildAndSendUpdate(*state, 0x12a, 0x13, (void *)state[2]);
    }
    if ((state[0x1e] != 0 && state[0x17] >= 0x1540 && state[0x17] <= 0x2178)
        || (state[0x1e] == 0 && state[0x17] >= 0x2200 && state[0x17] <= 0x2ec0)) {
        Ov221_StrikeSweepEntities(state, 7, 0);
    }
    if (*(unsigned char *)(state[1] + 0xad) != 0) {
        return;
    }
    *(unsigned char *)(*state + 0x1c7) = 2;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
