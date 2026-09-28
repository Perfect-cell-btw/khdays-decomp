/* Store param_1 into the global data_ov009_020563ec; return 1. */
extern int data_ov009_020563ec;
int Ov009_SetHandlerA(int param_1) {
    *(int *)&data_ov009_020563ec = param_1;
    return 1;
}
