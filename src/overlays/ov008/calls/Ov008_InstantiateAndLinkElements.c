extern void Ov008_CreateWidget(void *context, void *entry);
extern void Ov008_BuildNodeWithChildren(void *context, void *entry);

void Ov008_InstantiateAndLinkElements(void *context, void *entries, int count)
{
    int i;

    i = 0;
    if (count > 0) {
        char *entry = entries;

        do {
            Ov008_CreateWidget(context, entry);
            entry += 0x58;
            i++;
        } while (i < count);
    }

    i = 0;
    if (count > 0) {
        do {
            Ov008_BuildNodeWithChildren(context, entries);
            i++;
            entries = (char *)entries + 0x58;
        } while (i < count);
    }
}
