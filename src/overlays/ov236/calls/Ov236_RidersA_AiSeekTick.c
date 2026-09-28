/* Spawn the child via 020cab14; if it appears mark state 0xa and dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov107_FindNearestObject(int, int);
void Ov236_RidersA_AiSeekTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int child = Ov107_FindNearestObject(*(int *)owner, 0);
    *(int *)(owner + 4) = child;
    if (child == 0) return;
    *(signed char *)(*(int *)owner + 0x1c7) = 0xa;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
