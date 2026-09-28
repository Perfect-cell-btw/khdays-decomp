/* Force the second ov025 id word to -1 and return 1. */

extern int data_ov025_020b574c;

int Ov025_ClearHandlerB(void) {
    if (*(int *)((char *)&data_ov025_020b574c + 4) != -1) {
        *(int *)((char *)&data_ov025_020b574c + 4) = -1;
    }
    return 1;
}
