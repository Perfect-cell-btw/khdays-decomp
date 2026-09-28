/* Ov025_ListViewUpdate -- per-frame update of the ov025 list view: run the two live sub-updates
 * (obj+0xc / obj+0x10), then, only when a relayout is pending (obj+0x2c4), refresh the arrows,
 * rows, offset and scrollbar, latch the new offset (0x2cc = 0x2c8) and clear the flag. */
extern void Ov025_ScrollList_TouchKnob(int obj);
extern void Ov025_ScrollList_EndDragOnRelease(int obj);
extern void Ov025_RefreshScrollArrows(int obj);
extern void Ov025_ScrollList_PlaceKnobBar(int obj);
extern void Ov025_ApplyComputedOffset(int obj);
extern void Ov025_ScrollList_PlaceMarkers(int obj);

void Ov025_ListViewUpdate(int param_1) {
    if (*(int *)(param_1 + 0xc) != 0) {
        Ov025_ScrollList_TouchKnob(param_1);
    }
    if (*(int *)(param_1 + 0x10) != 0) {
        Ov025_ScrollList_EndDragOnRelease(param_1);
    }
    if (*(int *)(param_1 + 0x2c4) == 0) {
        return;
    }
    Ov025_RefreshScrollArrows(param_1);
    Ov025_ScrollList_PlaceKnobBar(param_1);
    Ov025_ApplyComputedOffset(param_1);
    Ov025_ScrollList_PlaceMarkers(param_1);
    *(int *)(param_1 + 0x2cc) = *(int *)(param_1 + 0x2c8);
    *(int *)(param_1 + 0x2c4) = 0;
}
