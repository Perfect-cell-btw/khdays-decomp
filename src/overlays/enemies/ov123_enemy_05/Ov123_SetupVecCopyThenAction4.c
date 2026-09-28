extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov123_ShotFlightTick(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct ov123b_LowByteFlags { unsigned bits : 8; };
struct vec3 { int a, b, c; };

void Ov123_SetupVecCopyThenAction4(int *node) {
    int *state = (int *)node[1];
    state[9] = 0;
    state[10] = 0;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x9c;
    *(unsigned short *)(*state + 0x1ae) &= ~3;
    ((struct ov123b_LowByteFlags *)(*(int *)(*state + 0x388) + 8))->bits |= 1;
    *(struct vec3 *)(state + 0xb) = *(struct vec3 *)((int *)state[2]);
    Ov107_BuildAndSendUpdate(*state, 0x115, 4, state[2]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov123_ShotFlightTick);
}
