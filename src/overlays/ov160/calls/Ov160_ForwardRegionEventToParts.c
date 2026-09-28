extern void Ov107_InitObjectFromSource(void *a, int v);
extern void Ov107_HandleRegionEvent(void *a, void *b);

void Ov160_ForwardRegionEventToParts(char *a, void *b) {
    Ov107_InitObjectFromSource(b, *(int *)(a + 0x3a4));
    Ov107_HandleRegionEvent(a, b);
}
