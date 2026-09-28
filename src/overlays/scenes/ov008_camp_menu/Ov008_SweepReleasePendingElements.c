/* Releases every element marked for release. */

extern void Ov008_ReleaseElement(void *context, void *entry);

void Ov008_SweepReleasePendingElements(void *context)
{
    int count = *(int *)((char *)context + 0x34);
    int i = 0;

    if (count > 0) {
        int offset = 0;

        do {
            char *entry = *(char **)((char *)context + 0x10) + offset;

            if ((((unsigned int)*(unsigned char *)(entry + 0x24) << 30) >> 31) == 1) {
                Ov008_ReleaseElement(context, entry);
            }

            count = *(int *)((char *)context + 0x34);
            i++;
            offset += 0x30;
        } while (i < count);
    }
}
