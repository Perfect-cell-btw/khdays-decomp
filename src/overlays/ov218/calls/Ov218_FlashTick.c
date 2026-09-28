/* Tick of an ov218 flash helper: it ends when its owner's +0x394 effect is gone or after eight steps;
 * each 1.0 (+8) it advances its step (+0xc) and plays it on layer 4 of the +4 rig. */
extern void Task_MarkFinished(int *node);
extern void SetSubitemState(int rig, int channel, int a, int b);

void Ov218_FlashTick(int *node)
{
    int *state = (int *)node[1];

    if (*(int *)(*state + 0x394) == 0) {
        Task_MarkFinished(node);
        return;
    }
    state[2] += *(int *)(node[0] + 0x2c);
    if (state[2] < 0x1000) {
        return;
    }
    if (state[3] >= 8) {
        Task_MarkFinished(node);
        return;
    }
    state[2] = 0;
    state[3]++;
    SetSubitemState(state[1], 4, (short)state[3], 1);
}
