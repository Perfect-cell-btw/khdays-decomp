/* Scene entry: the context IS the current root heap block (nothing is allocated),
 * so latch it in data_ov002_0207f9f4 and zero its first 0x25 bytes, then register
 * the per-frame step at Ov002_LinkSyncOnPacket under slot 6. Returns the next scene
 * step. Same shape as Ov002_EnterDimmedScene. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, unsigned char value, unsigned int size);
extern void StoreGlobalPtrArray4At0c(int slot, void *fn);
extern void Ov002_LinkSyncOnPacket(void);
extern void Ov002_LinkSyncStep(void);

extern int data_ov002_0207f9f4;

void *Ov002_EnterLinkSyncScene(void) {
    void *ctx = NNSi_FndGetCurrentRootHeap();

    data_ov002_0207f9f4 = (int)ctx;
    MI_CpuFill8(ctx, 0, 0x25);
    StoreGlobalPtrArray4At0c(6, (void *)&Ov002_LinkSyncOnPacket);
    return (void *)&Ov002_LinkSyncStep;
}
