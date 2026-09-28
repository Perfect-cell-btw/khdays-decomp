extern void Ov179_SetTimerA000(int v);

void Ov179_ForwardToAiTaskWhenReady(char *p) {
    if (*(int *)(p + 0x50) != 1) return;
    Ov179_SetTimerA000(*(int *)(p + 0x214));
}
