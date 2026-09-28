struct b1 { unsigned char b : 1; };
extern int Ov107_ActionResource_GetOffsetAndScale(void *obj, int *vec);
extern void Vec3TransformViaTempMtx(void *dst, void *mtx, int *vec);
extern void ScaleVec3Fx12(int scale, void *v, void *out);
extern void VEC_Add(void *a, void *b, void *out);
extern void SetIndexedSlot(void *obj, int idx, void *value);

void Ov143_stAdvanceProjectilePose(char *obj) {
    int *state = *(int **)(obj + 4);
    int vec[3];
    int scale;
    scale = Ov107_ActionResource_GetOffsetAndScale(*(void **)(*state + 0x3cc), vec);
    Vec3TransformViaTempMtx((void *)(state + 6), (void *)(*state + 0xa0), vec);
    ScaleVec3Fx12(scale, (void *)(state + 6), (void *)(state + 6));
    VEC_Add((void *)(state + 6), (void *)(state + 9), (void *)(state + 6));
    ScaleVec3Fx12(0xb00, (void *)(state + 9), (void *)(state + 9));
    if (*(unsigned char *)state[0x11] == 0) {
        if (((struct b1 *)(*state + 0x17a))->b || ((struct b1 *)(*state + 0x17c))->b) {
            *(signed char *)(*state + 0x1c7) = 2;
            SetIndexedSlot(obj, *(signed char *)(obj + 0x20), (void *)0);
        }
    }
}
