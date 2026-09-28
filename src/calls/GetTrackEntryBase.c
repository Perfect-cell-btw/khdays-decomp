extern char *data_0204c208;

void *GetTrackEntryBase(int idx)
{
    return (void *)(data_0204c208 + 4 + (idx << 3));
}
