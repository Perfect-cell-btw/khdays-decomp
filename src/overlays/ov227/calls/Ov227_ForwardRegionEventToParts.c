extern int Ov107_InitObjectFromSource();
extern int Ov107_HandleRegionEvent();

int Ov227_ForwardRegionEventToParts(int *r0, int r1)
{
    int i;

    for (i = 0; i < 10; i++) {
        int v = r0[i + 0xfb];
        if (v) {
            Ov107_InitObjectFromSource(r1, v);
        }
    }
    return Ov107_HandleRegionEvent(r0, r1);
}
