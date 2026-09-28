extern int Ov002_GetCtxTableByte(int slot);
extern void Ov002_FireEntryOnce(void *node);
extern char data_ov002_0207fa20;

/* Walks all 24 spawn slots and tears down every object still queued on each live one. */
void Ov002_TeardownAllSpawnSlots(void) {
    int i;
    char *node;
    char *next;
    for (i = 0; i < 0x18; i++) {
        if (Ov002_GetCtxTableByte(i) >= 0) {
            node = ((char **)*(char **)((char *)&data_ov002_0207fa20 + 4))[i];
            while (node != 0) {
                next = *(char **)(node + 4);
                Ov002_FireEntryOnce(node);
                node = next;
            }
        }
    }
}
