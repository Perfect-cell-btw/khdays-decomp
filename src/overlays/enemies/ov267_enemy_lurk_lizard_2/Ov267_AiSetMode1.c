/* Run the local setup (mode 1) on *(child+4), then dispatch to the handler. */
extern void Ov267_SetMode70(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov267_AiQueue2OnAnimEnd(int);
void Ov267_AiSetMode1(int param_1) {
    Ov267_SetMode70(*(int *)(param_1 + 4), 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov267_AiQueue2OnAnimEnd);
}
