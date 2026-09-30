struct hw60 { unsigned short lo : 8, hi : 8; };

extern int Ov107_ActionResource_GetOffsetAndScale(int src, int *out);
extern void Vec3TransformViaTempMtx(int dst, int mtx, int *v);
extern void ScaleVec3Fx12(int s, int dst, int src);
extern void SetIndexedSlot(int obj, int a, int cb);
extern void Ov139_TriggerEffectSetFlag40ThenAdvance(void);

// Same transform+scale step as the cd5a4 handler, but gated on the linked
// object's ready byte (*node[0x50]): once it clears, drop hw60 flag 0x40 and
// advance to the cd788 sub-state.
void Ov139_TransformScaleUntilObjectReady(int *this)
{
    int node = this[1];
    int tmp[3];
    int scale = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*(int *)node + 0x390), tmp);
    Vec3TransformViaTempMtx(node + 0x14, *(int *)node + 0xa0, tmp);
    ScaleVec3Fx12(scale, node + 0x14, node + 0x14);
    if (*(unsigned char *)(*(int *)(node + 0x50)) != 0) {
        return;
    }
    ((struct hw60 *)(*(int *)node + 0x60))->hi &= ~0x40;
    SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), (int)&Ov139_TriggerEffectSetFlag40ThenAdvance);
}
