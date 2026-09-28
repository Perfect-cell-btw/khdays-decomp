/* ITCM getter: returns the word at +0x20 of the idx'th 0xC-byte entry of the table at
 * *(data_ov022_020b2e78 + 4). Returns 0 when the table pointer is null or the entry's +4 pointer is
 * null. Hot cross-overlay callee. Ov022_OnEndMessage reads that word as an actor and reaches its
 * reaction context at a fixed +0x2288, which is why the return type is Ov022Actor *. */

extern int data_ov022_020b2e78;

int GetEntryField20ByIndex(int idx) {
    int base = *(int *)((char *)&data_ov022_020b2e78 + 4);
    int entry;
    if (base == 0) return 0;
    entry = *(int *)(idx * 0xc + base + 4);
    if (entry == 0) return 0;
    return *(int *)(entry + 0x20);
}
