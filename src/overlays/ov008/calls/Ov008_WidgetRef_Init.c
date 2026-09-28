extern void *Ov008_GetContext(void);
extern void *Ov008_FindEntryById(void *context, int arg1);
extern void *Ov008_GetEntryPos(void *context, void *entry);
extern void MI_CpuCopy8(void *src, void *dst, int size);

void Ov008_WidgetRef_Init(void *out, short value)
{
    void *context = Ov008_GetContext();
    void *entry;

    *(short *)out = value;
    entry = Ov008_FindEntryById(context, *(short *)out);
    *(void **)((char *)out + 4) = entry;
    entry = *(void **)((char *)out + 4);
    MI_CpuCopy8(Ov008_GetEntryPos(context, entry), (char *)out + 8, 8);
}
