/* Passes the event to the child object (+0x3ac), then to the base region-event handler. */

extern int Ov107_InitObjectFromSource();
extern int Ov107_HandleRegionEvent();

int Ov170_ForwardEventToChild(int *r0, int r1) {
    Ov107_InitObjectFromSource(r1, r0[0x3ac / 4]);
    return Ov107_HandleRegionEvent(r0, r1);
}
