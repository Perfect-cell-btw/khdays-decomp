/* Tear down the ov002 context's two owned buffers and reset its slot tables:
 * free the heap block at +0 (clearing +0 and +4), release the handle at +8
 * through ZeroHalfThenFree and tell Ov002_SetRootWord8a28 channel 2 it is gone, then
 * fill the 0x18-byte table at +0x17 and the 4-byte table at +0x2f with 0xff --
 * 0xff being the empty-slot marker for those tables. */
extern int data_ov002_0207fa10;

extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern void ZeroHalfThenFree(void *handle);
extern void Ov002_SetRootWord8a28(int arg0, int arg1);
extern void MI_CpuFill8(void *dst, unsigned char val, unsigned int size);

void Ov002_ReleaseContextBuffers(void) {
    int *ctx = *(int **)&data_ov002_0207fa10;

    if (ctx[0] != 0) {
        NNSi_FndFreeFromDefaultHeap((void *)ctx[0]);
        ctx[0] = 0;
        ctx[1] = 0;
    }

    if (ctx[2] != 0) {
        ZeroHalfThenFree((void *)ctx[2]);
        ctx[2] = 0;
        Ov002_SetRootWord8a28(2, 0);
    }

    MI_CpuFill8((char *)ctx + 0x17, 0xff, 0x18);
    MI_CpuFill8((char *)ctx + 0x2f, 0xff, 4);
}
