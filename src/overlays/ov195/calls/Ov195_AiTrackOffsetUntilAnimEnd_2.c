extern int Ov107_ActionResource_GetOffsetAndScale();
extern int Vec3TransformViaTempMtx();
extern int ScaleVec3Fx12();
extern int SetIndexedSlot();

struct S0 { int *f0; int *f4; char pad[0x20 - 8]; signed char f20; };

struct Local { int a; int b; int c; };

void Ov195_AiTrackOffsetUntilAnimEnd_2(struct S0 *this)
{
    struct Local local;
    int *r6 = this->f4;
    int r5;

    r5 = Ov107_ActionResource_GetOffsetAndScale(((int **)r6[0])[0xf4], &local);
    Vec3TransformViaTempMtx((char *)r6 + 0x18, (char *)r6[0] + 0xa0, &local);
    ScaleVec3Fx12(r5, (char *)r6 + 0x18, (char *)r6 + 0x18);

    if (*((unsigned char *)((int *)r6[1]) + 0xad) != 0)
        return;

    *((char *)r6[0] + 0x1c7) = 2;
    SetIndexedSlot(this, (int)*((signed char *)this + 0x20), 0);
}
