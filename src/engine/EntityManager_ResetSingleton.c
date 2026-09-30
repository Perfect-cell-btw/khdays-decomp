/* Allocates the EntityManager singleton from the default heap if it is not there yet, clears the
 * whole thing, and zeroes a run of slot words. Six callers. Named from the allocate-if-null plus
 * memset shape; refine if a caller shows more. */

extern void *NNSi_FndAllocFromDefaultExpHeap(unsigned int size);
extern void MI_CpuFill8(void *dst, unsigned char val, unsigned int size);

extern void *gEntityMgr;

int EntityManager_ResetSingleton(void) {
    int i;

    if (gEntityMgr == 0) {
        gEntityMgr = NNSi_FndAllocFromDefaultExpHeap(0xa4d4);
    }
    MI_CpuFill8(gEntityMgr, 0, 0xa4d4);

    for (i = 0; i < 0x40; i++) {
        *(unsigned int *)((unsigned char *)gEntityMgr + i * 0x184 + 0x244) = 0x1000;
    }
    return 1;
}
