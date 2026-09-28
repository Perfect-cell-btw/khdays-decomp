/* Unlinks the two arrow cells. */

extern void Slot_UnlinkIfLinked(void *arg0, int arg1);
extern char *data_ov008_02090fac[];

void Ov008_Shop_HideArrows(void)
{
    char *base = data_ov008_02090fac[0];
    int *values = (int *)(base + 0xc54c);
    void *object = *(void **)(base + 0xbfb0);

    Slot_UnlinkIfLinked(object, values[0]);
    Slot_UnlinkIfLinked(object, values[1]);
}
