/* Detach hook of the ov260 enemy: unregisters its two +0x42c / +0x430 effects and the fifteen
 * +0x434 slots from the given list, then runs the base detach (020c7c1c). */
extern void Ov107_InvokeSlot0x74(int list, int item);
extern void Ov107_Actor_DetachFromRegion(char *self, int list);

void Ov260_DetachHook(char *self, int list)
{
    int i;

    Ov107_InvokeSlot0x74(list, *(int *)(self + 0x42c));
    Ov107_InvokeSlot0x74(list, *(int *)(self + 0x430));
    for (i = 0; i < 15; i++) {
        Ov107_InvokeSlot0x74(list, ((int *)(self + 0x434))[i]);
    }
    Ov107_Actor_DetachFromRegion(self, list);
}
