/* Ov148_BuildHeadingRotation takes the vec BY VALUE (r1/r2/r3 via ldm) plus a stack flag. */
struct vec { int x, y, z; };
extern void VEC_Subtract();
extern void Ov148_BuildHeadingRotation(int *obj, struct vec v, int flag);
extern void Ov107_PostTagUpdate(int owner, int a, int b);
extern void Ov148_SeedDefaultPoseAndAdvance(int owner, int a);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov148_FaceTargetCheckReach(void);

void Ov148_FaceTargetThenIdle(int self) {
    int *obj = *(int **)(self + 4);
    struct vec v;

    VEC_Subtract(*obj + 400, obj[3], &v);
    Ov148_BuildHeadingRotation(obj, v, 0);
    if (*(unsigned char *)(obj[1] + 0xad) == 0) {
        Ov107_PostTagUpdate(*obj, 3, 1);
        Ov148_SeedDefaultPoseAndAdvance(*obj, 1);
        SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov148_FaceTargetCheckReach);
    }
}
