/* Store param_1 into the global data_ov025_020b574c; return 1. */
extern int data_ov025_020b574c;
int Ov025_SetHandlerA(int param_1) {
    *(int *)&data_ov025_020b574c = param_1;
    return 1;
}
