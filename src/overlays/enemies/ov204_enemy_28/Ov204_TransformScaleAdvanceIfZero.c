extern void ScaleVec3Fx12(int factor, void *src, void *dst);
extern void Vec3TransformViaTempMtx(void *dst, void *mtx, int *vec);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern int Ov107_ActionResource_GetOffsetAndScale(void *obj, int *vec);
extern void Ov204_Action6IfHitFlagsSet(void);

void Ov204_TransformScaleAdvanceIfZero(int node)
{
    int vec[3];
    int *state = *(int **)(node + 4);
    int factor = Ov107_ActionResource_GetOffsetAndScale(*(void **)(*state + 0x390), vec);

    Vec3TransformViaTempMtx((void *)(state + 2), (void *)(*state + 0xa0), vec);
    ScaleVec3Fx12(factor, state + 2, state + 2);
    if (factor != 0) {
        return;
    }
    SetIndexedSlot((void *)node, *(signed char *)(node + 0x20), Ov204_Action6IfHitFlagsSet);
}
