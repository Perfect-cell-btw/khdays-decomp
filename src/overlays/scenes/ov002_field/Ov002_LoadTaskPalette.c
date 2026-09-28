extern int data_ov002_0207f634;

extern void Ov002_DestroyOwnedEntry(int pTask, int nResult);
extern void GetResourceSubBlock_CHAR(int nHandle, int *ppInfo);
extern void *NNS_FndAllocFromDefaultExpHeapEx(int nSize, int nAlign);
extern void MIi_CpuCopyFast(const void *pSource, void *pDest, int nSize);
extern void Ov002_EnqueueAndRecordCommand(int nKind, int nFlags, int pData, int pMeta, int nHandle);

/* Load the palette block for the task's resource: copy 0x40 bytes out of the
 * resource body into a fresh heap block, register it, and finish the task. */
void Ov002_LoadTaskPalette(int pTask)
{
    int pInfo;
    int pOwner;

    pOwner = *(int *)&data_ov002_0207f634;
    if (pOwner == 0) {
        Ov002_DestroyOwnedEntry(pTask, 1);
        return;
    }

    GetResourceSubBlock_CHAR(*(int *)(pTask + 8), &pInfo);

    *(int *)(pOwner + 0x1c) = (int)NNS_FndAllocFromDefaultExpHeapEx(0x40, 4);
    MIi_CpuCopyFast((const void *)(*(int *)(pInfo + 0x14) + 0x1a60),
                    (void *)*(int *)(pOwner + 0x1c), 0x40);

    Ov002_EnqueueAndRecordCommand(0x16, 0, *(int *)(pInfo + 0x14), *(int *)(pInfo + 0x10),
                        *(int *)(pTask + 8));
    Ov002_DestroyOwnedEntry(pTask, 0);
}
