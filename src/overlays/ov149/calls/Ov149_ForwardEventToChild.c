/* Passes the event to the child object (+0x3c8), then to the base region-event handler. */

extern void Ov107_InitObjectFromSource(void *a, int v);
extern void Ov107_HandleRegionEvent(void *a, void *b);

void Ov149_ForwardEventToChild(char *a, void *b) {
    Ov107_InitObjectFromSource(b, *(int *)(a + 0x3c8));
    Ov107_HandleRegionEvent(a, b);
}
