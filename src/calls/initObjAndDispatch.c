extern void AnmObj_InitTrackTable();
void initObjAndDispatch(int *p, int v) {
    p[0] = 0;
    p[2] = v;
    p[4] = 0;
    *(unsigned char *)((char *)p + 0x18) = 0x7f;
    p[1] = 0x1000;
    p[5] = 0;
    AnmObj_InitTrackTable(p, v);
}
