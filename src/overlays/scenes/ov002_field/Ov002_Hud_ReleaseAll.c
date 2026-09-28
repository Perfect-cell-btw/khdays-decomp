/* Release every sub-object of the ov002 panel set held at data_ov002_0207f628 --
 * fourteen of them, at fixed offsets -- then drop the pointer. A null pointer
 * skips straight to the (redundant) clear. */
extern int data_ov002_0207f628;

extern void ReleaseField74AndCleanup(void *sub);

void Ov002_Hud_ReleaseAll(void) {
    char *self = *(char **)&data_ov002_0207f628;

    if (self != 0) {
        ReleaseField74AndCleanup(self + 0xe8);
        ReleaseField74AndCleanup(self + 0x508);
        ReleaseField74AndCleanup(self + 0x1f0);
        ReleaseField74AndCleanup(self + 0x2f8);
        ReleaseField74AndCleanup(self + 0x400);
        ReleaseField74AndCleanup(self + 0x8cc);
        ReleaseField74AndCleanup(self + 0x9d4);
        ReleaseField74AndCleanup(self + 0xdc0);
        ReleaseField74AndCleanup(self + 0xec8);
        ReleaseField74AndCleanup(self + 0x1068);
        ReleaseField74AndCleanup(self + 0x1214);
        ReleaseField74AndCleanup(self + 0x132c);
        ReleaseField74AndCleanup(self + 0x610);
    }

    *(int *)&data_ov002_0207f628 = 0;
}
