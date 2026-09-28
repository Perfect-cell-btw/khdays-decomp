/* Bind param_2 to the sub-object at (param_1)+0x3b0, then run the ov107 attach for the pair. */
extern void Ov107_InitObjectFromSource(int a, int b);
extern void Ov107_HandleRegionEvent(int a, int b);
void Ov208_ForwardRegionEventToPart(int param_1, int param_2) {
    Ov107_InitObjectFromSource(param_2, *(int *)(param_1 + 0x3b0));
    Ov107_HandleRegionEvent(param_1, param_2);
}
