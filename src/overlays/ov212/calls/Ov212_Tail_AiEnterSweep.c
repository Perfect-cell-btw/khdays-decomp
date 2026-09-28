/* Copy 3 words from *(child)+0x74 into (child)+8 and register the handler. */
struct w3 { int a, b, c; };
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov212_ChargeSweep(int);
void Ov212_Tail_AiEnterSweep(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(struct w3 *)(child + 8) = *(struct w3 *)(*(int *)child + 0x74);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov212_ChargeSweep);
}
