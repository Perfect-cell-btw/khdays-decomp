extern void Ov107_InitObjectFromSource();
extern void Ov107_HandleRegionEvent();

void Ov199_AttachThreeSubNodesThenFinalize(int arg0, int arg1) {
    int i;
    for (i = 0; i < 3; i++)
        Ov107_InitObjectFromSource(arg1, ((int *)arg0)[i + 230]);
    Ov107_HandleRegionEvent(arg0, arg1);
}
