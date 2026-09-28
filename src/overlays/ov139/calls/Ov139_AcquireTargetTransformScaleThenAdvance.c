extern int Ov107_FindNearestObject(int a, int b);
extern int Ov107_ActionResource_GetOffsetAndScale(int src, int *out);
extern void Vec3TransformViaTempMtx(int dst, int mtx, int *v);
extern void ScaleVec3Fx12(int s, int dst, int src);
extern void Ov107_PostTagUpdate(int obj, int a, int b);
extern void SetIndexedSlot(int obj, int a, int cb);
extern void Ov139_PrepSubState2GuardField50(void);

// Acquire the target (node[1]); if none, force sub-state 2 and bail. Otherwise
// run the transform+scale step and, once the linked object's ready byte clears
// (*node[0x50]==0), switch to mode 4 and advance with the follow-up callback.
void Ov139_AcquireTargetTransformScaleThenAdvance(int *this)
{
    int node = this[1];
    int tmp[3];
    int target = Ov107_FindNearestObject(*(int *)node, 0);
    *(int *)(node + 4) = target;
    if (target == 0) {
        *(signed char *)(*(int *)node + 0x1c7) = 2;
        SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), 0);
        return;
    }
    {
        int scale = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*(int *)node + 0x390), tmp);
        Vec3TransformViaTempMtx(node + 0x14, *(int *)node + 0xa0, tmp);
        ScaleVec3Fx12(scale, node + 0x14, node + 0x14);
    }
    if (*(unsigned char *)(*(int *)(node + 0x50)) != 0) {
        return;
    }
    Ov107_PostTagUpdate(*(int *)node, 4, 0);
    SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), (int)&Ov139_PrepSubState2GuardField50);
}
