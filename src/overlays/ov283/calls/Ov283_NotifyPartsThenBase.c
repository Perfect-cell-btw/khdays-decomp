/* Invokes slot 0x74 on the two head parts and the sixteen segment parts, then the base handler. */

extern void Ov107_InvokeSlot0x74(int obj, int arg1);
extern void Ov107_Actor_DetachFromRegion(int obj, int arg1);

void Ov283_NotifyPartsThenBase(int *list, int target) {
    int i;
    for (i = 0; i < 2; i++)
        Ov107_InvokeSlot0x74(target, list[i + 0xe7]);
    for (i = 0; i < 16; i++)
        Ov107_InvokeSlot0x74(target, list[i + 0xe9]);
    Ov107_Actor_DetachFromRegion((int)list, target);
}
