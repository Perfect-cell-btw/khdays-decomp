/* If the "can act" hw60 bit 0 is set, pick a random hold time between the min (*node+0x224) and max
 * (*node+0x228), store it in node[10], enter the hold state (1), and register the think callback. */
struct hw60 { unsigned short lo : 8, hi : 8; };
extern int RandNextScaled();
extern void SetIndexedSlot(int self, int idx, int cb);

void Ov237_StartRandomHold(int param_1) {
    int *node = *(int **)(param_1 + 4);
    int lo;
    int range;
    if ((((struct hw60 *)(*node + 0x60))->lo & 1) == 0) {
        return;
    }
    lo = *(int *)(*node + 0x224);
    range = *(int *)(*node + 0x228) - lo;
    if (range < 0) {
        range = -range;
    }
    node[10] = lo + RandNextScaled(range + 1);
    *(char *)(*node + 0x1c7) = 1;
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), 0);
}
