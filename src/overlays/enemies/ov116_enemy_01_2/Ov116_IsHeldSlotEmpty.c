/* Whether the actor's held slot (+0x39c) is empty. */

int Ov116_IsHeldSlotEmpty(char *p) {
    return *(int *)(*(char **)(*(char **)(*(char **)(p + 4)) + 0x39c) + 4) == 0;
}
