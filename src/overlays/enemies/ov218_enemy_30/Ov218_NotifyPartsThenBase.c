/* Invokes slot 0x74 on the part objects, then the base handler. */

extern void Ov107_InvokeSlot0x74();
extern void Ov107_Actor_DetachFromRegion();

void Ov218_NotifyPartsThenBase(int arg0, int arg1) {
    int i;
    for (i = 0; i < 2; i++)
        Ov107_InvokeSlot0x74(arg1, ((int *)arg0)[i + 229]);
    Ov107_Actor_DetachFromRegion(arg0, arg1);
}
