/* Store param into the second ov025 global word and return 1. */

extern int data_ov025_020b574c;

int Ov025_SetHandlerB(int arg0) {
    *(int *)((char *)&data_ov025_020b574c + 4) = arg0;
    return 1;
}
