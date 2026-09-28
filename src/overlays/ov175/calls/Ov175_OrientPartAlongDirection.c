extern int VEC_Normalize();
extern int Quat_FromTwoVectors();
extern int Srt_SetRotationQuat();

struct s3 {
    int a;
    int b;
    int c;
};

extern struct s3 data_02042264;

void Ov175_OrientPartAlongDirection(int unused, char *obj) {
    struct s3 v10;
    char s0[16];

    if (VEC_Normalize(obj + 0xcc, &v10) < 8) {
        v10 = data_02042264;
    }
    Quat_FromTwoVectors(s0, &data_02042264, &v10);
    Srt_SetRotationQuat(*(int *)(obj + 0x390) + 4, s0);
}
