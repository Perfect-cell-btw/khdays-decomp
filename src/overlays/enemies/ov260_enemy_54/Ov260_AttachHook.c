/* Attach hook of the ov260 enemy: registers its two +0x42c / +0x430 effects and the fifteen
 * +0x434 slots with the given list, then runs the base attach (020c7b70). */
extern void Ov107_InitObjectFromSource(int list, int item);
extern void Ov107_HandleRegionEvent(char *self, int list);

void Ov260_AttachHook(char *self, int list)
{
    int i;

    Ov107_InitObjectFromSource(list, *(int *)(self + 0x42c));
    Ov107_InitObjectFromSource(list, *(int *)(self + 0x430));
    for (i = 0; i < 15; i++) {
        Ov107_InitObjectFromSource(list, ((int *)(self + 0x434))[i]);
    }
    Ov107_HandleRegionEvent(self, list);
}
