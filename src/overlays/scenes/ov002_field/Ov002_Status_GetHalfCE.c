extern int data_ov002_0207f618;

int Ov002_Status_GetHalfCE(int arg0) {
    return *(unsigned short *)(*(int *)&data_ov002_0207f618 + arg0 * 4 + 0xce);
}
