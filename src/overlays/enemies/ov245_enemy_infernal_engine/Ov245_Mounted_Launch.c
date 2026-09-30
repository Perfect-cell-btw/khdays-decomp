/* Clear +0xc and mark sub-state 1. */
void Ov245_Mounted_Launch(int param_1) {
    *(int *)(param_1 + 0xc) = 0;
    *(signed char *)(*(int *)param_1 + 0x1c7) = 1;
}
