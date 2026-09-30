extern char *data_ov026_02091368;
extern char *gGameState;
extern void Ov026_ShowEightDigitCells(int cell, void *row, int selected);

/* Redraws both three-entry columns, highlighting whichever row each column has selected. */
void Ov026_RedrawBothColumns(void) {
    char *panel = *(char **)&data_ov026_02091368 + 0xc254;
    int i;
    char *left = panel;
    char *right = panel + 0x60;
    for (i = 0; i < 3; i++) {
        Ov026_ShowEightDigitCells(*(int *)(*(char **)&gGameState + 8) + *(int *)(panel + 0xc8),
                            left, *(int *)(panel + 0xc0) == i ? 1 : 0);
        Ov026_ShowEightDigitCells(*(int *)(*(char **)&gGameState + 0xc) + *(int *)(panel + 0xcc),
                            right, *(int *)(panel + 0xc4) == i ? 1 : 0);
        left += 0x20;
        right += 0x20;
    }
}
