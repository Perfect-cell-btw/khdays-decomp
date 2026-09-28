/* Initialises an animation object: clears its state, sets its resource, speed 1.0 and default
 * ratio, then builds its track table. */

extern void AnmObj_InitTrackTable();
void initObjAndDispatch(int *p, int v) {
    p[0] = 0;
    p[2] = v;
    p[4] = 0;
    *(unsigned char *)((char *)p + 0x18) = 0x7f;
    p[1] = 0x1000;
    p[5] = 0;
    AnmObj_InitTrackTable(p, v);
}
