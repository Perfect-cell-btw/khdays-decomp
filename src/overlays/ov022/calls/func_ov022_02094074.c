extern int Ov022_IsActiveAndCountPositive(unsigned char *arg0);
int func_ov022_02094074(unsigned char *arg0) {
    if (!Ov022_IsActiveAndCountPositive(arg0)) return arg0[1] == 0;
    return 1;
}
