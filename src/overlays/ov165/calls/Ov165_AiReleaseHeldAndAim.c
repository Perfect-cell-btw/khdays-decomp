extern int Ov107_UnlinkNodeFromOwner();
extern int Ov107_ActionResource_GetOffsetAndScale();
extern int Vec3TransformViaTempMtx();
extern int ScaleVec3Fx12();
extern int SetIndexedSlot();

void Ov165_AiReleaseHeldAndAim(int this) {
    int s = *(int *)(this + 4);
    int p = *(int *)s;
    int local[3];
    int r6;

    if (*(int *)(p + 0x3d0) != 0) {
        Ov107_UnlinkNodeFromOwner();
        *(int *)(*(int *)s + 0x3d0) = 0;
    }

    p = *(int *)s;
    r6 = Ov107_ActionResource_GetOffsetAndScale(*(int *)(p + 0x3c8), local);

    Vec3TransformViaTempMtx(s + 0x18, *(int *)s + 0xa0, local);

    ScaleVec3Fx12(r6, s + 0x18, s + 0x18);

    p = *(int *)s;
    if (((unsigned int)(*(unsigned char *)(p + 0x17a) << 0x1f) >> 0x1f) == 0) {
        return;
    }
    if (*(unsigned char *)(*(int *)(s + 0x58)) != 0) {
        return;
    }

    *(unsigned char *)(p + 0x1c7) = 2;
    SetIndexedSlot(this, *(signed char *)(this + 0x20), 0);
}
