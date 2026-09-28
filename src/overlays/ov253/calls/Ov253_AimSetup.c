/* Ov253_AimSetup -- aim setup: takes the scene camera's look direction (+0x20 minus
 * +0x14), keeps its length at +8 and builds the +0xc rotation to face it from data_02042258;
 * the +4 item's +0x74 position is kept at +0x20, the rotation's forward scaled by the length
 * gives an aim point kept at least 1.0 above the +0x24 height, which is sent as event 4 to the
 * owner's +0x74 handler when present; the +0x1c timer clears and slots 1 / 2 take 020d1d28 /
 * 020d1cf0. */
typedef struct { int x, y, z; } Vec3;

extern int func_ov022_02083f0c(void);
extern int Ov002_GetWord20(int handle);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void Quat_FromTwoVectors(void *rotation, const Vec3 *from, const Vec3 *to);
extern void Vec3TransformViaTempMtx(Vec3 *out, void *rotation, const Vec3 *in);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int func_ov107_020c9848();
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const Vec3 data_02042258;
extern void Ov253_AimFollow(void);
extern void Ov253_ForwardEvent4(void);

void Ov253_AimSetup(int *node) {
    int *state = (int *)node[1];
    Vec3 dir;
    Vec3 aim;
    Vec3 fwd;
    int cam;
    int obj;
    int arg;

    cam = Ov002_GetWord20(func_ov022_02083f0c());
    VEC_Subtract((Vec3 *)(cam + 0x20), (Vec3 *)(cam + 0x14), &dir);
    state[2] = VEC_Normalize(&dir, &dir);
    Quat_FromTwoVectors((void *)(state + 3), &data_02042258, &dir);
    *(Vec3 *)(state + 8) = *(Vec3 *)(state[1] + 0x74);
    Vec3TransformViaTempMtx(&fwd, (void *)(state + 3), &data_02042258);
    ScaleVec3Fx12(state[2], &fwd, &aim);
    VEC_Add(&aim, (Vec3 *)(state + 8), &aim);
    if (aim.y < state[9] + 0x1000) {
        aim.y = state[9] + 0x1000;
    }
    if (*(int *)(func_ov107_020c9848() + 0x74) != 0) {
        obj = func_ov107_020c9848();
        arg = func_ov022_02083f0c();
        (*(void (**)(int, int, Vec3 *))(obj + 0x74))(arg, 4, (Vec3 *)(state + 8));
    }
    state[7] = 0;
    SetIndexedSlot(node, 1, Ov253_AimFollow);
    SetIndexedSlot(node, 2, Ov253_ForwardEvent4);
}
