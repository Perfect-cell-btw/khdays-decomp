extern int data_ov022_020b2e78;

int GetEntryField20ByIndex(int idx) {
    int base = *(int *)((char *)&data_ov022_020b2e78 + 4);
    int entry;
    if (base == 0) return 0;
    entry = *(int *)(idx * 0xc + base + 4);
    if (entry == 0) return 0;
    return *(int *)(entry + 0x20);
}
