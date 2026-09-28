extern int Ov107_InitObjectFromSource();
extern int Ov107_HandleRegionEvent();

int Ov248_ForwardEventToChildren(int *r0, int r1) {
    int i;
    for (i = 0; i < 8; i++) {
        Ov107_InitObjectFromSource(r1, r0[0xf0 + i]);
    }
    return Ov107_HandleRegionEvent(r0, r1);
}
