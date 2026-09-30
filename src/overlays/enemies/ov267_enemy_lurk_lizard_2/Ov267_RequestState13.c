/* Queues action 0xd unless it is the current one; returns whether it did. */

int Ov267_RequestState13(char *obj) {
    char *base = *(char **)(*(char **)(obj + 0x214));
    if (*(signed char *)(base + 0x1c6) != 0xd) {
        *(char *)(base + 0x1c7) = 0xd;
        return 1;
    }
    return 0;
}
