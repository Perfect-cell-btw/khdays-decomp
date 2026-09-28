/* Clears the slot's sub-phase when the caller's request word has bit 0 set. */
int Ov255_ClearSubPhaseIfRequested(char *self, int unused, int *request) {
    int *slot = *(int **)(self + 0x214);
    if (((unsigned short)*request & 1) == 0) {
        return 0;
    }
    *(char *)(*slot + 0x1c7) = 0;
    return 1;
}
