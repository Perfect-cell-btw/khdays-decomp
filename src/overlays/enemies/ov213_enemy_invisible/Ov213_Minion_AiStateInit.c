/* Clear the +0x1c6 byte, mark sub-state -1, set +4 = *(child)+0xb0 and register two handlers
 * in turn (slot 1 then slot 0). */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov213_Minion_AiLockAndResume(int);
extern void Ov213_ConsumePoseRequest(int);
void Ov213_Minion_AiStateInit(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(signed char *)(*(int *)child + 0x1c6) = 0;
    *(signed char *)(*(int *)child + 0x1c7) = -1;
    *(int *)(child + 4) = *(int *)child + 0xb0;
    SetIndexedSlot(param_1, 1, (void *)&Ov213_Minion_AiLockAndResume);
    SetIndexedSlot(param_1, 0, (void *)&Ov213_ConsumePoseRequest);
}
