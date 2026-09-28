extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void Vec3TransformViaTempMtx(void *dst, void *src, void *tmp);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov172_CarryDashTick(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct ov172_LowByteFlags { unsigned bits : 8; };
struct vec4 { int a, b, c, d; };
struct vec3 { int a, b, c; };

void Ov172_TransformVecThenAction5(int *node) {
    int *state = (int *)node[1];
    Ov107_BuildAndSendUpdate(*state, 0x140, 5, state[2]);
    *(struct vec4 *)(state + 8) = *(struct vec4 *)(*state + 0x390);
    state[0xc] = 0;
    state[0xd] = 0;
    state[0xe] = 0x500;
    Vec3TransformViaTempMtx(state + 0xc, state + 8, state + 0xc);
    state[0x12] = 0;
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x9c;
    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 1) << 0x18) >> 0x10);
    }
    ((struct ov172_LowByteFlags *)(*(int *)(*state + 0x388) + 8))->bits |= 1;
    *(struct vec3 *)(state + 0xf) = *(struct vec3 *)(*(int *)(*state + 0x38c) + 0xb0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov172_CarryDashTick);
}
