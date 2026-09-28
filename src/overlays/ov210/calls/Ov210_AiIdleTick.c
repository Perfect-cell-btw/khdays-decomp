/* If the sub-object at *(child+4)+4 exists, dispatch to the handler. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov210_SetupScatter(int);
void Ov210_AiIdleTick(int param_1) {
    if (*(int *)(*(int *)(param_1 + 4) + 4) == 0) return;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov210_SetupScatter);
}
