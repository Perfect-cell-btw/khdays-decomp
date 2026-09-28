/* Whether the opening's fade counter has reached 16. */

extern char *data_ov012_0205cb20;

int Ov012_IsCounterAt16(void) {
    return *(int *)(data_ov012_0205cb20 + 0x8be8) >= 0x10;
}
