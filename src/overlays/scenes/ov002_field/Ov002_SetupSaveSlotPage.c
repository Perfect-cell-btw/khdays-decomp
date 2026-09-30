extern char *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, int value, unsigned size);
extern void *NNS_FndAllocFromDefaultExpHeapEx(unsigned size, int align);
extern void MIi_CpuClearFast(int value, void *dst, unsigned size);
extern void Ov002_AppendEntry(void *desc, void *handler, int arg);
extern void Ov002_QueueScreenLoad(void);
extern int Ov002_Field_GetHalf84(void);
extern void Ov002_QueuePanelGraphics(void);
extern int Ov002_CreateStepNode(void *fn);
extern void Ov002_CommitWidgetPayload(void);
extern void Ov002_StepPageScroll(void);
extern void Ov002_DropPendingEdit(void);
extern char *data_ov002_0207f638;
extern int gOv002UiBtlBmLoBg002Path;

/* Sets up the save/load page: clears the scene block, allocates and clears the 0x12c0-byte entry
 * table, builds the button, and registers the row renderer; returns the page's tick handler. */
void *Ov002_SetupSaveSlotPage(void) {
    char *self = NNSi_FndGetCurrentRootHeap();
    data_ov002_0207f638 = self;
    MI_CpuFill8(self, 0, 0x44);
    *(void **)(self + 0x1c) = NNS_FndAllocFromDefaultExpHeapEx(0x4b << 6, 4);
    MIi_CpuClearFast(0, *(void **)(self + 0x1c), 0x4b << 6);
    Ov002_AppendEntry(&gOv002UiBtlBmLoBg002Path, (void *)&Ov002_CommitWidgetPayload, 0);
    Ov002_QueueScreenLoad();
    if (Ov002_Field_GetHalf84() != 0xffff) {
        Ov002_QueuePanelGraphics();
    }
    *(int *)(self + 0x34) = Ov002_CreateStepNode((void *)&Ov002_StepPageScroll);
    return (void *)&Ov002_DropPendingEdit;
}
