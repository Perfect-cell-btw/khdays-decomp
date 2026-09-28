extern void Ov180_SetTimerA000(int v);

void Ov180_ForwardToAiTaskWhenReady(char *p) {
    if (*(int *)(p + 0x50) != 1) return;
    Ov180_SetTimerA000(*(int *)(p + 0x214));
}
