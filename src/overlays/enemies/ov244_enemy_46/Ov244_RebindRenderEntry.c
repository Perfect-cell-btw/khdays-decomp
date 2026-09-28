/* Rebind the +0x88 owner's render object: remove its five hooked animation objects (+0xc..),
 * reset and free the entry at *pEntry, allocate a fresh 0x24-byte one seeded from the owner
 * with `tag` (kind 0xc), bind it to this item, bind channel 0 with (0, flag) and re-init. */
extern void NNS_G3dRenderObjRemoveAnmObj(void *renderObj, int anmObj);   /* NNS_G3dRenderObjRemoveAnmObj */
extern void FreeAllResourceTables(int entry);
extern void FreeInstanceMemory(int ptr);
extern int CallocInstance(int size);
extern void Snd_RegisterSeqAndBind(int entry, int owner, int tag, int kind);
extern void MainBlob_ResetSlotRows(int item, int entry);
extern void SetSubitemState(int item, int channel, int a, int flag);
extern void RefreshObjectCallbacks(int item, int a);

void Ov244_RebindRenderEntry(int item, int tag, int flag, int *pEntry) {
    int i;
    int *owner = *(int **)(item + 0x88);
    for (i = 0; i < 5; i++) {
        if (owner[i + 3] != 0) {
            NNS_G3dRenderObjRemoveAnmObj((char *)owner + 0x20, owner[i + 3]);
            owner[i + 3] = 0;
        }
    }
    FreeAllResourceTables(*pEntry);
    FreeInstanceMemory(*pEntry);
    *pEntry = CallocInstance(0x24);
    Snd_RegisterSeqAndBind(*pEntry, (int)owner, tag, 0xc);
    MainBlob_ResetSlotRows(item, *pEntry);
    SetSubitemState(item, 0, 0, flag);
    RefreshObjectCallbacks(item, 0);
}
