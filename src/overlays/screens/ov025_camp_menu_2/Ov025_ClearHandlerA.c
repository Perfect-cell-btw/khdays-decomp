/* Force the first ov025 id word to -1 and return 1. */

extern int data_ov025_020b574c;

int Ov025_ClearHandlerA(void) {
    if (data_ov025_020b574c != -1) {
        data_ov025_020b574c = -1;
    }
    return 1;
}
