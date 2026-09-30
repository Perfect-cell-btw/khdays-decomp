/* AI step: once the actor is active (bit 0 of its flags at +0x60), clears the step's counters and
 * velocity, makes the stored action (+0x1c9) pending and clears the step handler. */

struct hw60 { unsigned short lo : 8, hi : 8; };
struct v3 { int a, b, c; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern int data_02041dc8[];

void Ov264_stEnterClearAndPose(int *node) {
    int *state = (int *)node[1];
    if ((((struct hw60 *)(*state + 0x60))->lo & 1) == 0) return;
    state[0x15] = 0;
    state[0x16] = 0;
    state[0x17] = 0;
    state[0x18] = 0;
    state[0x19] = 0;
    state[0x1a] = 0;
    *(struct v3 *)(state + 5) = *(struct v3 *)data_02041dc8;
    *(signed char *)(*state + 0x1c7) = *(signed char *)(*state + 0x1c9);
    SetIndexedSlot(node, *(signed char *)(node + 8), (void *)0);
}
