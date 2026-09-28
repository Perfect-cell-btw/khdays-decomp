/* Tear the HUD context down: run the three sub-teardowns, then clear the 4-byte
 * field at +0xfc and the 0x80-byte block at +0x7c. The context pointer is read
 * once up front and is dead after the last clear, which is why the ROM advances
 * r4 in place instead of recomputing the base. */
extern void Ov002_ReleaseLinkCollections(void);
extern void Ov002_FreeWorkBuffer(void);
extern void Ov002_ReleaseContextBuffers(void);
extern void MI_CpuFill8(void *dst, unsigned char value, unsigned int size);
extern void INITi_CpuClear32_0x01ff86fc();

extern int data_ov002_0207fa10;

void Ov002_TearDownContext(void) {
    int ctx = data_ov002_0207fa10;

    Ov002_ReleaseLinkCollections();
    Ov002_FreeWorkBuffer();
    Ov002_ReleaseContextBuffers();
    MI_CpuFill8((void *)(ctx + 0xfc), 0, 4);
    INITi_CpuClear32_0x01ff86fc(0, ctx + 0x7c, 0x80);
}
