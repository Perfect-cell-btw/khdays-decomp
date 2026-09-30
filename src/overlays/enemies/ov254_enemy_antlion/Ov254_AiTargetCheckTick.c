/* Unless busy, poll 020cd080: on success just dispatch, otherwise latch sub-state 4 first. */
extern int Ov254_CheckTarget(int);
extern int SetIndexedSlot(int, int, void *);
void Ov254_AiTargetCheckTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    if (Ov254_CheckTarget(param_1) != 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    } else {
        *(unsigned char *)(*(int *)owner + 0x1c7) = 4;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    }
}
