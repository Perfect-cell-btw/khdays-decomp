struct Vec3_02095dc8 {
    long x;
    long y;
    long z;
};

struct AnchorBlock_02095dc8 {
    unsigned char pad000[0x400];
    struct Vec3_02095dc8 anchor400;
};

struct Obj_02095dc8 {
    unsigned char pad000[0x8c];
    struct AnchorBlock_02095dc8 anchor08c;
};

extern _Bool Ov022_ValidateTargetRef(const struct Obj_02095dc8 *obj);
extern const struct Vec3_02095dc8 *func_ov022_020ad0c0(const struct Obj_02095dc8 *obj);
extern void VEC_Subtract(const struct Vec3_02095dc8 *a,
                         const struct Vec3_02095dc8 *b,
                         int *out);
extern int VEC_Mag(const int *v);
extern int Ov022_GetByte2770(const struct Obj_02095dc8 *obj);

int Ov022_TestAnchorReachable(const struct Obj_02095dc8 *arg0) {
    const struct Vec3_02095dc8 *anchor;
    int result = 0;
    int stack[3];
    anchor = &arg0->anchor08c.anchor400;
    if (Ov022_ValidateTargetRef(arg0)) {
        const struct Vec3_02095dc8 *p;
        p = func_ov022_020ad0c0(arg0);
        VEC_Subtract(p, anchor, stack);
        stack[1] = result;
        if (p->y - anchor->y >= 0x2000) {
            if (VEC_Mag(stack) <= 0x6000) {
                if (Ov022_GetByte2770(arg0) != 1) {
                    result = 1;
                }
            }
        }
    }
    return result;
}
