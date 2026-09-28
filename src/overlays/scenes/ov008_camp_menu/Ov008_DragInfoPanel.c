/* Ov008_DragInfoPanel -- drag the mission-info panel with the stylus.
 * Reads the touch state (Ov008_CopySourceBlock); if the pen is down, scrolls to
 * (touchY - height/2 - 0x3f) clamped to [0, 0x60 - height] (Ov008_DetailPanel_SetScroll).
 * On pen-up it clears the drag anchor (obj+0x158). */
extern void Ov008_CopySourceBlock(unsigned short *touch);
extern void Ov008_DetailPanel_SetScroll(int obj, int pos);

void Ov008_DragInfoPanel(int param_1) {
    unsigned short touch[4];
    Ov008_CopySourceBlock(touch);
    if (touch[2] != 0) {
        int pos = ((int)touch[1] - *(int *)(param_1 + 0x164) / 2) - 0x3f;
        int lim;
        if (pos < 0) {
            pos = 0;
        }
        lim = 0x60 - *(int *)(param_1 + 0x164);
        if (pos > lim) {
            pos = lim;
        }
        Ov008_DetailPanel_SetScroll(param_1, pos);
        return;
    }
    *(int *)(param_1 + 0x158) = 0;
}
