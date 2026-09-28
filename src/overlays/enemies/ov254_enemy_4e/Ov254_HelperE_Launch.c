/* Clear +0x48 and mark sub-state 1. */
void Ov254_HelperE_Launch(int param_1) {
    *(int *)(param_1 + 0x48) = 0;
    *(signed char *)(*(int *)param_1 + 0x1c7) = 1;
}
