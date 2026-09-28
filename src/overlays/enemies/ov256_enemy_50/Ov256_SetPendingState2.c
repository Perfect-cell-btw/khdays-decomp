/* Queues action 2. */

void Ov256_SetPendingState2(char *obj) {
    char *p = *(char **)obj;
    *(char *)(p + 0x1c7) = 2;
}
