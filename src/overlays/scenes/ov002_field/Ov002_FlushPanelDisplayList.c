/* Refresh the panel when bit 2 of the state word at +0x12c is set, then -- only
 * while Ov002_World_IsFlagBit2Set agrees -- flush the display list at +0xbc if there
 * is a target at +0x4c. The state word at +0x18c is cleared either way once the
 * flush point is reached. */
extern void Ov002_RetuneAmbientEmitter(void);
extern int Ov002_World_IsFlagBit2Set(void);
extern void EnqueueObjGfxCommand(void *list);

extern char *data_ov002_0207f614;

void Ov002_FlushPanelDisplayList(void) {
    char *ctx = data_ov002_0207f614;

    if ((unsigned int)(*(int *)(ctx + 0x12c) << 0x1d) >> 0x1f) {
        Ov002_RetuneAmbientEmitter();
    }

    if (Ov002_World_IsFlagBit2Set() == 0) {
        return;
    }

    if (*(int *)(ctx + 0x4c) != 0) {
        EnqueueObjGfxCommand(ctx + 0xbc);
    }

    *(int *)(ctx + 0x18c) = 0;
}
