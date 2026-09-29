/* Releases one hold on sleep mode (data_0204bda0, never below zero); returns the remaining count. */

extern int data_0204bda0;

int Sleep_Unblock(void) {
    int v = *(short *)&data_0204bda0;
    if (v > 0) {
        v -= 1;
        *(short *)&data_0204bda0 = v;
    }
    return v;
}
