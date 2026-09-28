/* Returns the value (+0xc) of the indexed peer record of the field context. */

extern int data_ov002_0207fa10;

int Ov002_GetPeerRecordValue(int arg0) {
    int a = *(int *)&data_ov002_0207fa10;
    int b = *(int *)(a + 4);
    int c = *(int *)(b + arg0 * 4 + 4);
    return *(int *)(c + 0xc);
}
