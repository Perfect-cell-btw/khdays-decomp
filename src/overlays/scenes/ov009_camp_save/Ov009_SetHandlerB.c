/* Store param into the second ov009 global word and return 1. */
extern int data_ov009_020563ec;
int Ov009_SetHandlerB(int param_1) {
    (&data_ov009_020563ec)[1] = param_1;
    return 1;
}
