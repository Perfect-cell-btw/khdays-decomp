/* Turn entry of the ov260 actor: with a +8 target it faces it from the +0x10 point (+0x64 / +0x68
 * heading), pose 8 plays, +0x7c, the target and the +0x79 flag clear and the node moves on to
 * 020d02ac. */
typedef unsigned char u8;
typedef struct { int x, y, z; } Vec3;

extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int func_020050b4(int x, int y);
extern void Ov107_PostTagUpdate(int actor, int pose, int loop);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov260_TickRecovery(void);

void Ov260_TurnEntry(int *node)
{
    int *state = (int *)node[1];
    Vec3 d;

    if (state[2] != 0) {
        VEC_Subtract((Vec3 *)(state[2] + 0x190), (Vec3 *)state[4], &d);
        state[0x19] = state[0x1a] = func_020050b4(d.x, d.z);
    }
    Ov107_PostTagUpdate(*state, 8, 0);
    state[0x1f] = 0;
    state[2] = 0;
    *((u8 *)state + 0x79) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov260_TickRecovery);
}
