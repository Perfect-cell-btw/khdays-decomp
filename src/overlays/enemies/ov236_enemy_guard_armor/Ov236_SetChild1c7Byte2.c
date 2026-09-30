/* Queues action 2 on the step's actor. */

void Ov236_SetChild1c7Byte2(char *obj) {
    char *p = *(char **)*(char **)(obj + 4);
    *(char *)(p + 0x1c7) = 2;
}
