/* Updates the shared HUD record at +0x8ba8: -2 leaves the id alone entirely, -1 refreshes
 * without touching it, any other value writes it (and a negative one first stashes the old
 * id at +0x18).  The payload at +8 is always written.
 *
 * The -2 and -1 sentinels come from one materialised constant: the ROM does `movs r1,#1 /
 * mvns r1,r1` for -2 and then `adds r1,r1,#1` for -1, which is what `m2` and `m2 + 1` give. */
extern char *data_ov002_0207fa00;
extern void Ov002_World_SetPendingEntryOnce(int a);

void Ov002_UpdateHudRecord(int id, int slot, int payload) {
    char *o = data_ov002_0207fa00 + 0x8ba8;
    int m2 = -2;
    if (id != m2) {
        if (id != m2 + 1) {
            *(int *)(o + 0x10) = id;
        }
        Ov002_World_SetPendingEntryOnce(1);
    }
    if (slot != -1) {
        if (slot < 0) {
            *(int *)(o + 0x18) = *(short *)(o + 2);
        }
        *(short *)(o + 2) = (short)slot;
    }
    *(int *)(o + 8) = payload;
}
