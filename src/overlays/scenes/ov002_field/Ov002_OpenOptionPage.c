extern void Ov002_DestroyOwnedEntry(char *self, int mode);
extern void *NNS_FndAllocFromDefaultExpHeapEx(unsigned size, int align);
extern int Ov002_GetWord8(char *self);
extern void GetResourceSubBlock_CHAR(int a, char *p);
extern char *data_ov002_0207f634;

/* Opens the option page: allocates its 0x40-byte state, registers the widget and starts the
 * layout at +0x28. */
void Ov002_OpenOptionPage(char *self) {
    char *page = data_ov002_0207f634;
    if (page == 0) {
        Ov002_DestroyOwnedEntry(self, 1);
        return;
    }
    *(void **)(page + 0x14) = NNS_FndAllocFromDefaultExpHeapEx(0x40, 4);
    *(int *)(page + 0x10) = Ov002_GetWord8(self);
    GetResourceSubBlock_CHAR(*(int *)(page + 0x10), page + 0x28);
    Ov002_DestroyOwnedEntry(self, 0);
}
