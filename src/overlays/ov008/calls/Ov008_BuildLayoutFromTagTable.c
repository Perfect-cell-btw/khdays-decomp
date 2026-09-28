extern void Ov008_BuildTagTrackerNode(void *context, unsigned short arg1, void *arg2, unsigned short arg3, int arg4, int arg5, int arg6);

void Ov008_BuildLayoutFromTagTable(void *context, void *data)
{
    unsigned int count = *(unsigned int *)data;
    unsigned int i;
    char *entry;

    entry = (char *)data + 4;
    i = 0;

    while (i < count) {
        Ov008_BuildTagTrackerNode(context, *(unsigned short *)(entry + 0xc), entry + 0x10, *(unsigned short *)(entry + 0xe), *(int *)(entry + 4), *(int *)(entry + 8), 0);
        i++;
        entry += *(unsigned int *)entry;
    }
}
