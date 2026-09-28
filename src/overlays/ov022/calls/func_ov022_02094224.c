extern int Ov022_IsBit0Set_5(int a);
extern int Sequence_UpdateTracks(unsigned short *a, int b);

struct vec3_02094224 {
    int a;
    int b;
    int c;
};

struct flags_02094224 {
    unsigned char lo4 : 4;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char hi2 : 2;
};

void func_ov022_02094224(int param_1, struct vec3_02094224 *param_2, int param_3) {
    if (Ov022_IsBit0Set_5(param_1) == 0) {
        return;
    }
    if (*(int *)(param_1 + 0x110) > 0) {
        *(int *)(param_1 + 0x110) -= param_3;
        if (*(int *)(param_1 + 0x110) <= 0) {
            *(int *)(param_1 + 0x110) = 0;
        }
    }
    if (*(int *)(param_1 + 0x10c) > 0) {
        *(int *)(param_1 + 0x10c) -= param_3;
    }
    if (*(int *)(param_1 + 0x10c) < 0) {
        *(int *)(param_1 + 0x10c) = 0;
    }
    if ((*(unsigned char *)param_1 & 0x20) != 0) {
        *(struct vec3_02094224 *)(param_1 + 0xa8) = *param_2;
        if (Sequence_UpdateTracks((unsigned short *)(param_1 + 4), param_3) != 0) {
            ((struct flags_02094224 *)param_1)->b4 = 0;
            ((struct flags_02094224 *)param_1)->b5 = 0;
        }
    }
}
