extern void Ov107_InitObjectFromSource();
extern void Ov107_HandleRegionEvent();

void Ov245_Carrier_ForwardRegionEventToParts(int arg0, int arg1) {
    int i;
    for (i = 0; i < 3; i++)
        Ov107_InitObjectFromSource(arg1, ((int *)arg0)[i + 229]);
    Ov107_HandleRegionEvent(arg0, arg1);
}
