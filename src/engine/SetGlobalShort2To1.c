/* Stores a fixed halfword into a global field. */

extern int data_0204be08;

void SetGlobalShort2To1(void) {
    *(short *)((char *)&data_0204be08 + 2) = 1;
}
