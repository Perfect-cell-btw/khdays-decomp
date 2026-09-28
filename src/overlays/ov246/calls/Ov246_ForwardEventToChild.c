extern int Ov107_InitObjectFromSource();
extern int Ov107_HandleRegionEvent();

int Ov246_ForwardEventToChild(int *r0, int r1) {
    Ov107_InitObjectFromSource(r1, r0[0x3a0 / 4]);
    return Ov107_HandleRegionEvent(r0, r1);
}
