/* Run the local setup (mode 1) on *(child+4), then dispatch to the handler. */
extern void Ov266_SetMode70(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov266_AiQueue2OnAnimEnd(int);
void Ov266_AiSetMode1(int param_1) {
    Ov266_SetMode70(*(int *)(param_1 + 4), 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov266_AiQueue2OnAnimEnd);
}
