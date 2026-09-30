/* Allocates the entity manager's record table (n entries of 0x14 bytes). */

extern void *NNSi_FndAllocFromDefaultExpHeap(int size);
extern char *gEntityMgr;

void EntityMgr_AllocRecords(int n) {
    *(void **)(gEntityMgr + 0x61c4) = NNSi_FndAllocFromDefaultExpHeap(n * 0x14);
    *(int   *)(gEntityMgr + 0x61c8) = n;
}
