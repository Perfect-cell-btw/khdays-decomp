/* Clears a pointer of the global object and the two halfword counters before it. */

extern int data_0204be08;

void ClearGlobalPtrE8AndHead(void) {
    *(int *)(*(int *)((char *)&data_0204be08 + 4) + 0xe8) = 0;
    *(short *)&data_0204be08 = 0;
    *(short *)((char *)&data_0204be08 + 2) = 0;
}
