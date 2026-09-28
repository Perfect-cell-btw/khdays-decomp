extern void Ov107_InitObjectFromSource(void *a, int v);
extern void Ov107_HandleRegionEvent(void *a, void *b);

void Ov238_ForwardRegionEventToPart(char *a, void *b) {
    Ov107_InitObjectFromSource(b, *(int *)(a + 0x384));
    Ov107_HandleRegionEvent(a, b);
}
