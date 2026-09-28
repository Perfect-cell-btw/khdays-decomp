/* If the +0x3dc flag of *(*self+0x38c) is set, mark sub-state 1. */
void Ov254_HelperD_QueueAction1IfArmed(int param_1) {
    int obj = *(int *)param_1;
    if (*(int *)(*(int *)(obj + 0x38c) + 0x3dc) != 0)
        *(signed char *)(obj + 0x1c7) = 1;
}
