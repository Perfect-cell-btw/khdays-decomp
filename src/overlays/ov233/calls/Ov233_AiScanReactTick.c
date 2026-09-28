/* Accumulate the owner rate (+0x2c) into the timer at (child)+0x20; while below 0x2a8 keep
 * running the sub-update (020d238c). Then, unless the gate byte at *(*child+0x384)+0xad is
 * set, reset the sub-state byte (+0x1c7) and dispatch. */
extern void Ov233_ScanNearbyEntitiesReact(int);
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov233_AiScanReactTick(int param_1) {
    int child = *(int *)(param_1 + 4);
    int t = *(int *)(child + 0x20) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x20) = t;
    if (t <= 0x2a8) Ov233_ScanNearbyEntitiesReact(child);
    if (*(unsigned char *)(*(int *)(*(int *)child + 0x384) + 0xad) != 0) return;
    *(signed char *)(*(int *)child + 0x1c7) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
