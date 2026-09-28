extern char *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, int value, unsigned size);
extern void NNS_FndInitList(void *list, int offset);
extern void Ov002_LoadArchiveResource(int a);
extern void *NNSi_FndAllocFromDefaultExpHeap(unsigned size);
extern void MIi_CpuCopyFast(const void *src, void *dst, unsigned size);
extern void Ov002_TickEntryPool(void);
extern char *data_ov002_0207f61c;

/* Sets the panel page up from the caller's descriptor: clears the state, starts the entry list,
 * copies the 0xe0-byte layout out of the archive and returns the page's tick handler. */
void *Ov002_SetupPanelPage(int *desc) {
    char *self = NNSi_FndGetCurrentRootHeap();
    data_ov002_0207f61c = self;
    MI_CpuFill8(self, 0, 0x20);
    NNS_FndInitList(self + 0x10, 0x54);
    *(int *)(self + 0xc) = desc[1];
    Ov002_LoadArchiveResource(desc[0]);
    *(void **)(self + 4) = NNSi_FndAllocFromDefaultExpHeap(0xe0);
    MIi_CpuCopyFast((char *)desc[2] + 0x2b20, *(void **)(self + 4), 0xe0);
    return (void *)&Ov002_TickEntryPool;
}
