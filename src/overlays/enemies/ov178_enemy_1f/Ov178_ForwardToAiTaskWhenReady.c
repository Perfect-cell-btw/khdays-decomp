extern void Ov178_SetTimerA000(int v);

void Ov178_ForwardToAiTaskWhenReady(char *p) {
    if (*(int *)(p + 0x50) != 1) return;
    Ov178_SetTimerA000(*(int *)(p + 0x214));
}
