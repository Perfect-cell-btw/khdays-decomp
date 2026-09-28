extern int Ov107_ActionResource_GetOffsetAndScale(int a, void *out);
extern void Vec3TransformViaTempMtx(int a, int b, void *c);
extern void ScaleVec3Fx12(int a, int b, int c);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov188_AiDelayThenAnim10(void);

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov188_ApplyAimThenClearFlag(int *self) {
    int v[3];
    int *s = (int *)self[1];
    int r = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*s + 0x3c0), v);
    Vec3TransformViaTempMtx((int)s + 0x20, *s + 0xa0, v);
    ScaleVec3Fx12(r, (int)s + 0x20, (int)s + 0x20);
    if (*(unsigned char *)(s[1] + 0xad) != 0) return;
    Ov107_PostTagUpdate(*s, 9, 1);
    ((struct hw60 *)(*s + 0x60))->hi &= ~0x40;
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), (void *)&Ov188_AiDelayThenAnim10);
}
