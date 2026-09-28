extern void Ov070_BindRig(int a);

void Ov070_initClearSubBlockField10(int param_1, int param_2) {
    int i;
    Ov070_BindRig(param_1);
    i = 0;
    do {
        i++;
        *(int *)(param_2 + 0x10) = 0;
        param_2 += 0x118;
    } while (i < 2);
}
