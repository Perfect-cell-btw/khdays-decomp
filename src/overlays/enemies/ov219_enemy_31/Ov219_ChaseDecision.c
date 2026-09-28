/* Chase decision of the ov219 enemy (and its byte-identical twin): a negative distance to the
 * target ends the state; otherwise, once the +4 item is idle, the actor plays animation 4
 * (looped), publishes a zero vector to the item with mode 1 and hands off to the chase tick. */
typedef unsigned char u8;
struct Vecx32 { int x, y, z; };

extern int Ov219_DistanceToTarget(int *node);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov107_PostTagUpdate(int actor, int anim, int flag);
extern void func_ov107_020c0b90(int actor, int a, struct Vecx32 v, int b);
extern const struct Vecx32 data_02041dc8;
extern void Ov219_ChaseTick(int *node);

void Ov219_ChaseDecision(int *node)
{
    int *state = (int *)node[1];

    if (Ov219_DistanceToTarget(node) < 0) {
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    if (*(u8 *)(state[1] + 0xad) == 0) {
        Ov107_PostTagUpdate(*state, 4, 1);
        func_ov107_020c0b90(*state, 1, data_02041dc8, 0);
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov219_ChaseTick);
    }
}
