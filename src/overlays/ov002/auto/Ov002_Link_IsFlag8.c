extern int data_ov002_0207fa08;

int Ov002_Link_IsFlag8(void) {
    return (*(int *)*(int *)&data_ov002_0207fa08 & 8) > 0;
}
