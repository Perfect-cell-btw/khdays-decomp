extern int data_ov002_0207f62c;

int Ov002_Field_HasPendingEvent(void) {
    int r = 0;
    if (*(unsigned short *)(*(int *)((char *)&data_ov002_0207f62c + 4) + 0x1de) != 0) {
        r = 1;
    }
    return r;
}
