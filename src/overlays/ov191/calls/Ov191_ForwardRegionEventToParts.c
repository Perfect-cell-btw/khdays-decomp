extern void Ov107_InitObjectFromSource(void *b, int v);
extern void Ov107_HandleRegionEvent(void *a, void *b);

void Ov191_ForwardRegionEventToParts(char *a, void *b) {
    int i;
    for (i = 0; i < 4; i++) {
        int *base = *(int **)(a + 0x3a4);
        Ov107_InitObjectFromSource(b, base[i]);
    }
    Ov107_HandleRegionEvent(a, b);
}
