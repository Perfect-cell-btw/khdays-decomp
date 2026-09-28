extern char *NNSi_FndGetCurrentRootHeap(void);
extern void StoreGlobalPtrArray4At0c(int slot, void *handler);
extern void MI_CpuFill8(void *dst, int value, unsigned size);
extern void func_ov022_0208a1a4(void);
extern int Session_GetLocalPlayerIndex(void);
extern void Ov022_PublishRecord(void);
extern void func_ov022_020897dc(void);
extern void Ov022_PublishRequestToSlot(void);
extern void Ov022_DispatchEntryByKind(void);
extern void func_ov022_02089704(void);
extern char *data_ov022_020b2ea4;

/* Sets the pause menu up: registers its four input handlers, clears the state block and -- on
 * the single-card path -- invalidates the four peer slots. Returns the tick handler. */
void *Ov022_SetupPauseMenu(void) {
    char *self = NNSi_FndGetCurrentRootHeap();
    int i;
    data_ov022_020b2ea4 = self;
    *(int *)self = 0;
    StoreGlobalPtrArray4At0c(2, (void *)&Ov022_PublishRecord);
    StoreGlobalPtrArray4At0c(0, (void *)&func_ov022_020897dc);
    StoreGlobalPtrArray4At0c(3, (void *)&Ov022_PublishRequestToSlot);
    StoreGlobalPtrArray4At0c(0xf, (void *)&Ov022_DispatchEntryByKind);
    MI_CpuFill8(self + 0x14, 0, 0xa4);
    MI_CpuFill8(self + 0x14, 0, 0xc4);
    func_ov022_0208a1a4();
    if (Session_GetLocalPlayerIndex() == 0) {
        for (i = 0; i < 4; i++) {
            *(unsigned short *)(self + 0xb0) = 0xffff;
            self += 2;
        }
    }
    return (void *)&func_ov022_02089704;
}
