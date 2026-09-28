extern int Ov022_IsBit0Set_5(unsigned char *p);
extern int Ov022_IsActiveAndCountPositive(unsigned char *p);

int func_ov022_020940a0(unsigned char *param_1, int param_2) {
    if (Ov022_IsBit0Set_5(param_1) == 0) {
        return 0;
    }
    if (param_2 >= 0) {
        if ((*param_1 & 4) == 0) {
            if (*(int *)(param_1 + 0x114) > param_2) {
                return 0;
            }
        } else {
            if (0x6000 < param_2 && *(int *)(param_1 + 0x114) > param_2) {
                return 0;
            }
        }
    }
    if (Ov022_IsActiveAndCountPositive(param_1) == 0 && 0 < *(int *)(param_1 + 0x10c)) {
        return 0;
    }
    return 1;
}
