extern int Ov107_FindNearestObject(int a, int b);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov197_SteerTrailThenAdvance(void);

typedef struct { int x, y, z; } Vec3;
extern Vec3 data_02041dc8;
extern void func_ov107_020c0b90(int a, int b, Vec3 v, int d);

void Ov197_SpawnTrailOrFail(int *self) {
    int *s = (int *)self[1];
    *(int *)(*s + 0x394) = Ov107_FindNearestObject(*s, 0);
    if (*(int *)(*s + 0x394) == 0) {
        *(signed char *)(*s + 0x1c7) = 2;
        SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), 0);
        return;
    }
    Ov107_PostTagUpdate(*s, 6, 0);
    func_ov107_020c0b90(*s, 0, *(Vec3 *)(*s + 0x3d8), 0);
    func_ov107_020c0b90(*s, 2, data_02041dc8, 0);
    s[0x10] = 0;
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), (void *)&Ov197_SteerTrailThenAdvance);
}
