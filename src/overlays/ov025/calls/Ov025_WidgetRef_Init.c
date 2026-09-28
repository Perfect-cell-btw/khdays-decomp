extern void *Ov025_GetContext(void);
extern void *Ov025_FindEntryById(void *context, int arg1);
extern void *Ov025_ApplyFirstValidSlot(void *context, void *entry);
extern void MI_CpuCopy8(void *src, void *dst, int size);

void Ov025_WidgetRef_Init(void *out, short value)
{
    void *context = Ov025_GetContext();
    void *entry;

    *(short *)out = value;
    entry = Ov025_FindEntryById(context, *(short *)out);
    *(void **)((char *)out + 4) = entry;
    entry = *(void **)((char *)out + 4);
    MI_CpuCopy8(Ov025_ApplyFirstValidSlot(context, entry), (char *)out + 8, 8);
}
