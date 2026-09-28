/* Per-frame model update: run the animator; while the current kind is 8 and bit 1 of the
 * +0x384 list's +0x5c word is set, finalize that list (0203c86c mode 1). Then place the +0x3f8
 * transform at the actor's +0xb0 position lowered by 0x2000 and pushed 0x2000 towards the
 * camera's +0x88 focus. */
typedef struct { int x, y, z; } Vec3;
struct ListFlags5c { int b0 : 1; int b1 : 1; };

extern void Ov107_ProcessObjectTick(int self);
extern void DispatchObjectCallbacks(int list, int a);
extern char *func_ov107_020c9848(void);   /* the game's camera-state getter, named after the byte-identical SDK thunk */
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(Vec3 *v, Vec3 *out);
extern void ScaleVec3Fx12(int scale, Vec3 *v, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern void SrtTransform_SetIdentity(void *srt);
extern void Srt_SetTranslation(void *srt, Vec3 *translation);

void Ov273_UpdateModelTransform(int self) {
    Vec3 dir;
    Vec3 at;

    Ov107_ProcessObjectTick(self);
    if (*(signed char *)(self + 0x100 + 0xc6) == 8) {
        if (((struct ListFlags5c *)(*(int *)(self + 0x384) + 0x5c))->b1 != 0) {
            DispatchObjectCallbacks(*(int *)(self + 0x384), 1);
        }
    }
    at = *(Vec3 *)(self + 0xb0);
    at.y -= 0x2000;
    VEC_Subtract((Vec3 *)(*(char **)func_ov107_020c9848() + 0x88), &at, &dir);
    VEC_Normalize(&dir, &dir);
    ScaleVec3Fx12(0x2000, &dir, &dir);
    VEC_Add(&at, &dir, &at);
    SrtTransform_SetIdentity((void *)(self + 0x3f8));
    Srt_SetTranslation((void *)(self + 0x3f8), &at);
}
