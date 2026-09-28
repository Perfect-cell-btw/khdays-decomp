/* Frees the buffers of every element that has one. Returns the element count (+0x38), which
 * Ov008_SweepElements passes on. */

extern void Ov008_FreeElementBuffer(void *context, void *entry);

int Ov008_SweepFreeElementBuffers(void *context)
{
    int count = *(int *)((char *)context + 0x38);
    int i = 0;

    if (count > 0) {
        int offset = 0;

        do {
            char *entry = *(char **)((char *)context + 0x14) + offset;

            if (*(int *)(entry + 0xc) != 0) {
                Ov008_FreeElementBuffer(context, entry);
            }

            count = *(int *)((char *)context + 0x38);
            i++;
            offset += 0x10;
        } while (i < count);
    }
    return count;
}
