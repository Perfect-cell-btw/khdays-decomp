extern int Ov107_ActionResource_GetOffsetAndScale(void *obj, int *vec);
extern void Vec3TransformViaTempMtx(void *dst, void *mtx, int *vec);
extern void ScaleVec3Fx12(int scale, void *v, void *out);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov150_020d256c[];

void Ov150_stTransformProjectilePose(char *obj) {
    int *state = *(int **)(obj + 4);
    short pair[2];
    int vec[3];
    int scale;
    scale = Ov107_ActionResource_GetOffsetAndScale(*(void **)(*state + 0x3cc), vec);
    Vec3TransformViaTempMtx((void *)(state + 6), (void *)(*state + 0xa0), vec);
    ScaleVec3Fx12(scale, (void *)(state + 6), (void *)(state + 6));
    if (*(unsigned char *)state[0x11] == 0) {
        short *pp = pair;
        void (*cb)();
        pp[1] = data_ov150_020d256c[1];
        pp[0] = data_ov150_020d256c[0];
        cb = *(void (**)())(*state + 0x24);
        if (cb != 0) cb(*state, pp, 4);
        *(signed char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(obj, *(signed char *)(obj + 0x20), (void *)0);
    }
}
