/* Ov023_RebuildVisibleEntries -- rebuild every visible entry of the 0x40-entry table at +0x440 of the VM
 * state; entries whose bit 2 is set in LoadArrayU8At0cc's flags are skipped. Always reports 1.
 *
 * Two shapes are load-bearing. The table pointer is reached as `((int *)obj)[0x4a]`, an ARRAY
 * INDEX: written as `*(int *)(obj + 0x128)` mwcc hoists the 0x128 into a callee-saved register
 * where the ROM rebuilds it (`movs #0x4a ; lsls #2`) at each use, which costs 4 bytes and steals
 * the register the mask wants. And the whole loop sits INSIDE the guard rather than after an
 * early `return 1`, so the single exit is shared. */
extern void EntityMgr_PopVramState(int obj);
extern int LoadArrayU8At0cc(unsigned short i);
extern void Ov023_ActorRelease(int p);

int Ov023_RebuildVisibleEntries(int obj) {
    int i;
    int off;
    int mask;
    EntityMgr_PopVramState(obj);
    if (*(int *)(((int *)obj)[0x4a] + 0x440) != 0) {
        i = 0;
        off = i;
        mask = 4;
        do {
            if ((LoadArrayU8At0cc((unsigned short)i) & mask) == 0) {
                Ov023_ActorRelease(*(int *)(((int *)obj)[0x4a] + 0x440) + off);
            }
            i = i + 1;
            off = off + 0x1a64;
        } while (i < 0x40);
    }
    return 1;
}
