/* Record the value for the given row at +0x1c4, then -- only once the transition
 * has finished, and only when the row is the one the empty/non-empty state at
 * +0x54 selects -- refresh the panel. */
extern int Ov002_Hud_IsPanelOpen(void);
extern void Ov002_RetuneAmbientEmitter(void);

extern char *data_ov002_0207f614;

void Ov002_SetRowValue(int row, int value) {
    *(int *)(data_ov002_0207f614 + row * 4 + 0x1c4) = value;

    if (Ov002_Hud_IsPanelOpen() != 0) {
        return;
    }
    if (row != (*(int *)(data_ov002_0207f614 + 0x54) == 0)) {
        return;
    }
    Ov002_RetuneAmbientEmitter();
}
