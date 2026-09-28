/* Inits the part objects from the event, then the base region handler. */

extern void Ov107_InitObjectFromSource(void *b, int v);
extern void Ov107_HandleRegionEvent(void *a, void *b);

void Ov151_ForwardRegionEventToParts(char *a, void *b) {
    int i;
    for (i = 0; i < 3; i++) {
        int *base = *(int **)(a + 0x3c8);
        Ov107_InitObjectFromSource(b, base[i]);
    }
    Ov107_HandleRegionEvent(a, b);
}
