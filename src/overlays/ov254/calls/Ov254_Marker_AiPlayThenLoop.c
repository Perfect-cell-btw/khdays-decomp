/* Unless the child is busy, kick anim (1, phase 1) and dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov254_Marker_IdleStep(int);
void Ov254_Marker_AiPlayThenLoop(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 1, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_Marker_IdleStep);
}
