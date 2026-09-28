/* Set *(*self)+0x394 = 1 and mark sub-state 1. */
void Ov256_Shard_Launch(int param_1) {
    *(int *)(*(int *)param_1 + 0x394) = 1;
    *(signed char *)(*(int *)param_1 + 0x1c7) = 1;
}
