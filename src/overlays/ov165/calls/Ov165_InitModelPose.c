/* Model pose init of the ov163 enemy (x3: ov163/164/165), variant of the matched ov202 sibling:
 * copies the +0x3c0 item's transform into +0x394, then moves its translation 0x800 towards the
 * camera's +0x88 focus (direction normalised from the pose position). */
typedef struct { int x, y, z; } Vec3;

typedef struct {
    int data[11];
} Mat;

typedef struct {
    char pad0[0x394];
    Mat mat;
    char *src;
} Obj;

extern void Ov107_AiState_DispatchModelCallbacks(Obj *obj);
extern char *func_ov107_020c9848(void);   /* the game's camera-state getter, named after the byte-identical SDK thunk */
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(Vec3 *v, Vec3 *out);
extern void ScaleVec3Fx12(int scale, Vec3 *v, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern void Srt_SetTranslation(Mat *mat, Vec3 *translation);

void Ov165_InitModelPose(Obj *obj) {
    Vec3 at;
    Vec3 dir;

    Ov107_AiState_DispatchModelCallbacks(obj);

    obj->mat = *(Mat *)(obj->src + 4);

    VEC_Subtract((Vec3 *)(*(char **)func_ov107_020c9848() + 0x88), (Vec3 *)((char *)&obj->mat + 16), &dir);
    VEC_Normalize(&dir, &dir);
    ScaleVec3Fx12(0x800, &dir, &at);
    VEC_Add((Vec3 *)((char *)&obj->mat + 16), &at, &at);
    Srt_SetTranslation(&obj->mat, &at);
}
