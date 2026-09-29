/* SlotTable_SetEntryVelocity -- set entry velocity/scale field and re-commit, MAIN.
 * For entry idx in the 0x8c-byte table at base, stores -(scale<<11) into field +0xc
 * (a fixed-point downward magnitude), then calls PrioList_Resort to recompute/commit the
 * entry (passing base, entry+4, &base[1], entry). */
extern void PrioList_Resort(int *a, int *b, int *c, int d);
void SlotTable_SetEntryVelocity(void *pBase, int idx, int scale) {
    int *base = (int *)pBase;
    char *e4;
    if (idx < 0) {
        return;
    }
    e4 = (char *)(base + 1) + idx * 0x8c;
    *(int *)((char *)base + idx * 0x8c + 0xc) = scale * -0x800;
    PrioList_Resort(base, (int *)e4, base + 1, (int)base + idx * 0x8c);
}
