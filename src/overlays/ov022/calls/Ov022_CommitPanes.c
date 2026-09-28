/* Commit both 0x164-byte panes -- each pane's dirty byte sits one past the pane
 * body at +0xda8 -- then flush the shared surface at +0x910. */
extern void Ov002_ReleaseSlotObject(void *pane);
extern void Ov022_TearDownActionTable(void *surface);

void Ov022_CommitPanes(char *self) {
    char *row;
    char *pane;
    int i;

    i = 0;
    row = self;
    pane = self + 0xda8;

    for (; i < 2; i++) {
        if (*(signed char *)(row + 0xda9) != 0) {
            Ov002_ReleaseSlotObject(pane);
        }

        row += 0x164;
        pane += 0x164;
    }

    Ov022_TearDownActionTable(self + 0x910);
}
