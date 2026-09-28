/* Bind param_2 to the sub-object at *(*(param_1)+0x3d4), then run the ov107 attach. */
extern void Ov107_InitObjectFromSource(int a, int b);
extern void Ov107_HandleRegionEvent(int a, int b);
void Ov210_ForwardRegionEventToShield(int param_1, int param_2) {
    Ov107_InitObjectFromSource(param_2, *(int *)*(int *)(param_1 + 0x3d4));
    Ov107_HandleRegionEvent(param_1, param_2);
}
