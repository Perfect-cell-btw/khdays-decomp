/* Ov253_CarryTick -- carry tick: seats the +0x3bc target's +0x18c rider (its +0x20 child)
 * at the +0x384 item's +0x394 joint anchor; once the +0x1c timer passes 0.625 sprite request 4
 * (data_ov253_020d4964[0] with the actor's +2 id) is dispatched, the rider is detached
 * (020ad8e0 / 020ad838) and the node moves to 020d0730. */
struct hpair { unsigned short a, b; };

extern void Actor_SetVecAndSyncChild(int node, void *pos);
extern void MsgQueue_Post(int a, void *req, int b);
extern void Ov022_ToggleBit13ByMode(int target, int a);
extern void func_ov022_020ad838(int target, int a);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const struct hpair data_ov253_020d4964[];
extern void Ov253_ThrowRelease(void);

void Ov253_CarryTick(int *node) {
    int *state = (int *)node[1];

    Actor_SetVecAndSyncChild(*(int *)(*(int *)(*(int *)(*state + 0x3bc) + 0x18c) + 0x20),
                  (void *)(*(int *)(*(int *)(*state + 0x384) + 0x394) + 0x14));
    state[7] += *(int *)(node[0] + 0x2c);
    if (state[7] < 0xa00) {
        return;
    }
    {
        struct hpair buf = data_ov253_020d4964[0];
        buf.a = *(unsigned short *)(*state + 2);
        MsgQueue_Post(4, &buf, 4);
    }
    Ov022_ToggleBit13ByMode(*(int *)(*(int *)(*state + 0x3bc) + 0x18c), 0);
    func_ov022_020ad838(*(int *)(*(int *)(*state + 0x3bc) + 0x18c), 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov253_ThrowRelease);
}
