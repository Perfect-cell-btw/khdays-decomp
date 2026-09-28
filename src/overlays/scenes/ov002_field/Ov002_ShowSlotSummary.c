extern void Ov002_DestroyOwnedEntry(char *self, int mode);
extern int Ov002_Field_GetHalf86(void);
extern char *Ov002_SnapshotChainEntry(int slot, int a, int b);
extern int Ov002_MakeSecondaryVramKey(unsigned int id);
extern void Ov002_AppendEntry(int text, void *handler, int arg);
extern void Ov002_SetCachedString(char *p);
extern void Ov002_SwapOwnerBlock(void);
extern char *data_ov002_0207f638;

/* Slot handler for the save page: resolves the slot record, and on the first pass announces its
 * name and shows the summary block; then closes. */
void Ov002_ShowSlotSummary(char *self, int again) {
    char *entry;
    if (data_ov002_0207f638 == 0) {
        Ov002_DestroyOwnedEntry(self, 1);
        return;
    }
    entry = Ov002_SnapshotChainEntry(*(int *)(self + 8), Ov002_Field_GetHalf86(), 1);
    if (again == 0) {
        Ov002_AppendEntry(Ov002_MakeSecondaryVramKey((unsigned short)*(int *)(entry + 0x14)),
                            (void *)&Ov002_SwapOwnerBlock, 0);
    }
    Ov002_SetCachedString(entry + *(unsigned short *)(entry + 4));
    Ov002_DestroyOwnedEntry(self, 1);
}
