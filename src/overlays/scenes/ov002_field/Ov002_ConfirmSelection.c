/* Confirm the current selection, but only while bit 2 of the state word at
 * +0x110 is set: close the sub-panel, relayout, play the sound the context
 * carries at +0x198 and park the panel state at +0x18c on 2. */
extern void Ov002_SetPanelMode(int a);
extern void Ov002_ResetFaders(void);
extern void PlaySoundChecked(int a, int sound);

extern char *data_ov002_0207f614;

void Ov002_ConfirmSelection(void) {
    char *ctx = data_ov002_0207f614;

    if (((unsigned int)(*(int *)(ctx + 0x110) << 0x1d) >> 0x1f) == 0) {
        return;
    }

    Ov002_SetPanelMode(1);
    Ov002_ResetFaders();
    PlaySoundChecked(0, *(int *)(ctx + 0x198));
    *(int *)(ctx + 0x18c) = 2;
}
