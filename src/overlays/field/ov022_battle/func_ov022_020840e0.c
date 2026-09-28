extern int data_ov022_020b2e6c;
extern void Ov022_ReadSelectionInput(void);

int func_ov022_020840e0(void) {
    int v = ((int *)&data_ov022_020b2e6c)[1];
    if (v > 2) {
        return (int)Ov022_ReadSelectionInput;
    }
    ((int *)&data_ov022_020b2e6c)[1] = v + 1;
    return 0;
}
