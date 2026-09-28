extern int data_ov002_0207fa10;

signed char Ov002_GetCtxModeByte(void) {
    return *(signed char *)(*(int *)&data_ov002_0207fa10 + 0xc);
}
