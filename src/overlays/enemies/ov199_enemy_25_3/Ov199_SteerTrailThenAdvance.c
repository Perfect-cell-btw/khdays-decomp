extern void VEC_Subtract(void *a, int b, void *out);
extern void VEC_Normalize(void *a, void *b);
extern int func_020050b4(int a, int b);
extern void Ov199_FireThreeWaySpread(int *s, int b, int c);
extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov199_AiStep_QueueAction2OnAnimEnd(void);

typedef struct { int x, y, z; } Vec3;
extern Vec3 data_02041dc8;

void Ov199_SteerTrailThenAdvance(int *self) {
    Vec3 v;
    int *s = (int *)self[1];
    int p;
    v = data_02041dc8;
    p = *(int *)(*s + 0x394);
    if (p != 0) {
        v = *(Vec3 *)(p + 0x74);
        v.y += *(int *)(*(int *)(*s + 0x398) + 0x80);
        VEC_Subtract(&v, *s + 0x3d8, &v);
        VEC_Normalize(&v, &v);
        s[0xe] = func_020050b4(v.x, v.z);
    }
    s[0x10] += *(int *)(*self + 0x2c);
    if (s[0x10] < 0x1188) return;
    Ov199_FireThreeWaySpread(s, v.y, *s + 0x3d8);
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), (void *)&Ov199_AiStep_QueueAction2OnAnimEnd);
}
