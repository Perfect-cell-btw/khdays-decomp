/* Aimed-attack wait of the ov125 enemy: the +0x2c timer accumulates the owner's +0x2c rate
 * and past 0x6ee the target is re-acquired (020cab14) into +4; with a target the aim matrix
 * at +0x68 is rebuilt from the target's +0x74 pose, the +0x24 anchor and data_02042264 and
 * copied down to +0x58. Bit 7 of the hw60 high byte is dropped, action 0/0 fired and the
 * follow-up state registered. */
struct hw60 { unsigned short lo : 8, hi : 8; };
struct blk16 { int a, b, c, d; };
extern int Ov107_FindNearestObject(int a, int b);
extern void Mtx33_LookAt(int *out, int *m, int *a, int *b);
extern void Quat_FromMtx33(int *dst, int *m);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern int data_02042264[];
extern void Ov126_AiRollTimerQueue2(void);
void Ov126_AimedAttackWait(int *node) {
    int buf[9];
    int *obj = (int *)node[0];
    int *state = (int *)node[1];
    int t = state[0xb] + obj[0xb];
    state[0xb] = t;
    if (t < 0x6ee) return;
    state[1] = Ov107_FindNearestObject(*state, 0);
    if (state[1] != 0) {
        int *sub = (int *)state[9];
        Mtx33_LookAt(buf, (int *)(state[1] + 0x74), sub, data_02042264);
        Quat_FromMtx33(state + 0x1a, buf);
        *(struct blk16 *)(state + 0x16) = *(struct blk16 *)(state + 0x1a);
    }
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x80;
    Ov107_PostTagUpdate(*state, 0, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov126_AiRollTimerQueue2);
}
