/* Ov146_NotifyPartsThenBase -- hand both sub-objects (+0x3b8, +0x3bc) to the visitor and then run the
 * base pass. The visitor takes (arg, object), not the other way round. */
extern void Ov107_InvokeSlot0x74(int arg, int obj);
extern void Ov107_Actor_DetachFromRegion(int obj, int arg);

void Ov146_NotifyPartsThenBase(int obj, int arg) {
    Ov107_InvokeSlot0x74(arg, *(int *)(obj + 0x3b8));
    Ov107_InvokeSlot0x74(arg, *(int *)(obj + 0x3bc));
    Ov107_Actor_DetachFromRegion(obj, arg);
}
