/* Refresh the shared panel: if the local player still owns the slot, hand the entry at +0x4ec
 * and its object to the panel refresh, then reset the four scroll words at +0x47c..+0x4b4.
 *
 * Matched byte-exact 2026-07-23, closing an old park filed as a register-coloring residue.
 * It was a DROPPED ARGUMENT: Ov107_Region_RequestLeave takes (obj, entry) -- it reads [r0,#0xf8] and
 * moves r1 into r4 -- and the park declared it `void (void)`. With both arguments live, `entry`
 * has to survive the load of its own field and mwcc puts it in r1, which is the whole residue.
 * The size was right the entire time, which is exactly why the arity was never suspected. */
extern int func_ov022_020882bc(unsigned int arg0);
extern int QueryActiveStateOrDelegate(void);
extern void Ov107_Region_RequestLeave(int obj, int *ent);

void Ov022_RefreshSharedPanel(int arg0) {
    unsigned int s = func_ov022_020882bc(*(unsigned char *)(arg0 + 9));
    int a = QueryActiveStateOrDelegate();
    int off;
    if (s == a) {
        int *ent = *(int **)(arg0 + 0x4ec);
        if (ent != 0 && ent[1] != 0) {
            Ov107_Region_RequestLeave(ent[1], ent);
        }
    }
    off = 0x4b4;
    *(int *)(arg0 + off) = 0xf000;
    *(int *)(arg0 + off - 0x30) = 0;
    *(int *)(arg0 + off - 0x34) = *(int *)(arg0 + off - 0x30);
    *(int *)(arg0 + off - 0x38) = *(int *)(arg0 + off - 0x34);
}
