/* Command callback 0: stores and queues action 2 and marks the command pending. */

void Ov261_RequestAction2(char *p) {
    p[0x1c9] = 2;
    p[0x1c7] = 2;
    *(int *)(p + 0x3a4) = 1;
    *(int *)(p + 0x3a8) = 0;
}
