extern void Slot_UnlinkIfLinked(void *p, int idx);

void Slot_UnlinkAll(void *p)
{
    int i;
    for (i = 0; i < 0x80; i++) {
        Slot_UnlinkIfLinked(p, i);
    }
}
