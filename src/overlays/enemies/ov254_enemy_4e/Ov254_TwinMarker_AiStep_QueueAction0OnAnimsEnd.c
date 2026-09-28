/* Unless either sibling is busy, mark state 0 and dispatch via c634. */
extern int SetIndexedSlot(int, int, int);
void Ov254_TwinMarker_AiStep_QueueAction0OnAnimsEnd(int param_1) {
    int obj = *(int *)(*(int *)(param_1 + 4));
    if (*(unsigned char *)(*(int *)(obj + 0x384) + 0xad) != 0 ||
        *(unsigned char *)(*(int *)(obj + 0x388) + 0xad) != 0) return;
    *(signed char *)(obj + 0x1c7) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
