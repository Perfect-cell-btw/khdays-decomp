/* Unless busy, cache the 020cab14 result at +0x420, mark state 4 and dispatch. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov107_FindNearestObject(int, int);
void Ov260_AiRetargetOnAnimEnd(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    int r = Ov107_FindNearestObject(*(int *)owner, 0);
    *(int *)(*(int *)owner + 0x420) = r;
    *(signed char *)(*(int *)owner + 0x1c7) = 4;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
