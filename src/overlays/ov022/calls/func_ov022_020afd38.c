extern int Ov022_IsBit0Set_3(unsigned char *arg0);
int func_ov022_020afd38(int arg0, int arg1) {
    int r = 0;
    int d = arg1 - *(int *)(arg0 + 0x490);
    if (d < 0x3000 || (Ov022_IsBit0Set_3((unsigned char *)(arg0 + 0x1198)) && d < 0x6000)) r = 1;
    return r;
}
