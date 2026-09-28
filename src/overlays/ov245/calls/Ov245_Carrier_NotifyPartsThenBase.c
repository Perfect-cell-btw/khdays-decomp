/* Invokes slot 0x74 on the three part objects, then the base handler. */

extern void Ov107_InvokeSlot0x74();
extern void Ov107_Actor_DetachFromRegion();

void Ov245_Carrier_NotifyPartsThenBase(int arg0, int arg1) {
    int i;
    for (i = 0; i < 3; i++)
        Ov107_InvokeSlot0x74(arg1, ((int *)arg0)[i + 229]);
    Ov107_Actor_DetachFromRegion(arg0, arg1);
}
