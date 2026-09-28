extern void ScaleVec3Fx12(int scale, void *src, void *dst);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov192_FlightTick(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct ov192_LowByteFlags { unsigned bits : 8; };
struct vec3 { int a, b, c; };

void Ov192_SetupScaledVecThenAction4(int *node) {
    int *state = (int *)node[1];
    state[0x10] = 0;
    state[9] = 0;
    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 1) << 0x18) >> 0x10);
    }
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x9c;
    ((struct ov192_LowByteFlags *)(*(int *)(*state + 0x388) + 8))->bits |= 1;
    *(struct vec3 *)(state + 5) = *(struct vec3 *)(*state + 0x394);
    ScaleVec3Fx12(0x500, state + 5, state + 2);
    state[8] = 0x500;
    Ov107_BuildAndSendUpdate(*state, 0x133, 4, state[1]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov192_FlightTick);
}
