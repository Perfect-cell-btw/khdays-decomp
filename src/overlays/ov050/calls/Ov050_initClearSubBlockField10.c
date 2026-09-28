extern void Ov050_BindRig(int a);

void Ov050_initClearSubBlockField10(int param_1, int param_2) {
    int i;
    Ov050_BindRig(param_1);
    i = 0;
    do {
        i++;
        *(int *)(param_2 + 0x10) = 0;
        param_2 += 0x118;
    } while (i < 2);
}
