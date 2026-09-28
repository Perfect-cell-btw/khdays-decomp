extern int Mtx33_LookAt();
extern int Quat_FromMtx33();
extern int data_02042264;

struct S {
    char pad0[4];
    int *field_4;
    char pad8[0x3c];
    int field_44;
};

void Ov186_LookAtQuat(struct S *r0, int r1)
{
    char local[0x24];
    Mtx33_LookAt(local, (char *)r0->field_4 + 0x74, r0->field_44, &data_02042264);
    Quat_FromMtx33(r1, local);
}
