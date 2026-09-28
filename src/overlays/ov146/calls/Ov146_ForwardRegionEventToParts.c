/* Ov146_ForwardRegionEventToParts -- hand both sub-objects (+0x3b8, +0x3bc) to the visitor and then run the
 * base pass. The visitor takes (arg, object), not the other way round. */
extern void Ov107_InitObjectFromSource(int arg, int obj);
extern void Ov107_HandleRegionEvent(int obj, int arg);

void Ov146_ForwardRegionEventToParts(int obj, int arg) {
    Ov107_InitObjectFromSource(arg, *(int *)(obj + 0x3b8));
    Ov107_InitObjectFromSource(arg, *(int *)(obj + 0x3bc));
    Ov107_HandleRegionEvent(obj, arg);
}
