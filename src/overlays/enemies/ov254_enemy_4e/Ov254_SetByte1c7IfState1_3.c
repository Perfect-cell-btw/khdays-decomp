/* In action 1, queues action 2. */

void Ov254_SetByte1c7IfState1_3(char *obj) {
    char *base = *(char **)obj;
    signed char v = *(signed char *)(base + 0x1c6);
    if (v == 1) {
        *(char *)(base + 0x1c7) = 2;
    }
}
