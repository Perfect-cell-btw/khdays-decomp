extern int data_ov002_0207f638;

extern void Ov002_DestroyOwnedEntry(int pTask, int nResult);
extern int Ov002_GetWord8(int pTask);
extern void NNSi_FndFreeFromDefaultHeap(void *pBlock);
extern void GetResourceSubBlock_CHAR(int nHandle, int *ppInfo);
extern void DC_FlushRange(void *pAddress, int nSize);

/* Swap in a freshly loaded block for the owner: drop the old one, take the
 * task's payload, resolve it, flush it to memory and mark the slot ready. */
void Ov002_SwapOwnerBlock(int pTask, int nSlot)
{
    int pOwner;

    pOwner = *(int *)&data_ov002_0207f638;
    if (pOwner == 0) {
        Ov002_DestroyOwnedEntry(pTask, 1);
        return;
    }

    *(unsigned char *)(pOwner + 0x28) = 0;

    if (*(void **)(pOwner + 0x2c) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(void **)(pOwner + 0x2c));
        *(int *)(pOwner + 0x2c) = 0;
    }

    *(int *)(pOwner + 0x2c) = Ov002_GetWord8(pTask);
    GetResourceSubBlock_CHAR(*(int *)(pOwner + 0x2c), (int *)(pOwner + 0x30));
    DC_FlushRange(*(void **)(*(int *)(pOwner + 0x30) + 0x14),
                  *(int *)(*(int *)(pOwner + 0x30) + 0x10));

    *(unsigned char *)(pOwner + 0x28) = 1;
    *(unsigned char *)(pOwner + 0x20) = (unsigned char)nSlot;
    Ov002_DestroyOwnedEntry(pTask, 0);
}
