extern int data_ov002_0207fa14;

int Ov002_GetOfferedKindEntry(void) {
    return *(int *)&data_ov002_0207fa14 + 0x96;
}
