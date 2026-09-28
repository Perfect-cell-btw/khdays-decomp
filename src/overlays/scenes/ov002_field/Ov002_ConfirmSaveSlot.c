extern void Ov002_DestroyOwnedEntry(char *self, int mode);
extern char *Ov002_SnapshotChainEntry(int slot, int a, int b);
extern int Ov002_MakeSecondaryVramKey(unsigned int id);
extern void Ov002_AppendEntry(int text, void *handler, int arg);
extern void Ov002_SwapOwnerBlock(void);
extern char *data_ov002_0207f638;

/* Confirm handler for the save slot page: with no page object it just closes, otherwise it
 * resolves the slot's name string and opens the confirmation prompt. */
void Ov002_ConfirmSaveSlot(char *self) {
    if (data_ov002_0207f638 == 0) {
        Ov002_DestroyOwnedEntry(self, 1);
        return;
    }
    Ov002_AppendEntry(
        Ov002_MakeSecondaryVramKey((unsigned short)*(int *)(Ov002_SnapshotChainEntry(*(int *)(self + 8), 0, 0) + 0x14)),
        (void *)&Ov002_SwapOwnerBlock, 1);
    Ov002_DestroyOwnedEntry(self, 1);
}
