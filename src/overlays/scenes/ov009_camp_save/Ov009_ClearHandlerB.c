/* Force the second ov009 id word to -1 and return 1. */
extern int data_ov009_020563ec;
int Ov009_ClearHandlerB(void) {
    if ((&data_ov009_020563ec)[1] != -1) (&data_ov009_020563ec)[1] = -1;
    return 1;
}
