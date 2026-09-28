#pragma thumb on
/* Ov023_SubPanelColumnStep -- map a sub-panel column index to its pixel step, ov023.
 * 0..3 -> 0/2/4/6; anything else -> index+9. */
int Ov023_SubPanelColumnStep(int col) {
    switch (col) {
    case 0: return 0;
    case 1: return 2;
    case 2: return 4;
    case 3: return 6;
    }
    return col + 9;
}
