/* Clears the element list, then runs the callback of every flagged element. */

extern void Ov008_ClearElementList(void *context, int arg1);
extern void Ov008_InvokeElementCallback(void *context, void *entry, int arg2);

void Ov008_FlushFlaggedElements(void *context, int arg1)
{
    int count;
    int i;

    Ov008_ClearElementList(context, arg1);
    count = *(int *)((char *)context + 0x30);
    i = 0;

    if (count > 0) {
        int offset = 0;

        do {
            char *entry = *(char **)((char *)context + 0xc) + offset;

            if (*(int *)(entry + 0x14) != 0) {
                Ov008_InvokeElementCallback(context, entry, arg1);
            }

            count = *(int *)((char *)context + 0x30);
            i++;
            offset += 0x38;
        } while (i < count);
    }
}
