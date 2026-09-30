/* AI step: resets the shot, clears the stance and contact bits, records its start position, sends
 * the shot update (0x115, mode 4) and continues with the shot flight. */

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov124_ShotFlightTick(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct ov124b_LowByteFlags { unsigned bits : 8; };
struct vec3 { int a, b, c; };

void Ov124_SetupVecCopyThenAction4(int *node) {
    int *state = (int *)node[1];
    state[9] = 0;
    state[10] = 0;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x9c;
    *(unsigned short *)(*state + 0x1ae) &= ~3;
    ((struct ov124b_LowByteFlags *)(*(int *)(*state + 0x388) + 8))->bits |= 1;
    *(struct vec3 *)(state + 0xb) = *(struct vec3 *)((int *)state[2]);
    Ov107_BuildAndSendUpdate(*state, 0x115, 4, state[2]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov124_ShotFlightTick);
}
