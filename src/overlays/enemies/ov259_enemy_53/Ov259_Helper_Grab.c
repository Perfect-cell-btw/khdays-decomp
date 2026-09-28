/* Set *(*self)+0x39c=1 and mark sub-state 3. */
void Ov259_Helper_Grab(int param_1) {
    *(int *)(*(int *)param_1 + 0x39c) = 1;
    *(signed char *)(*(int *)param_1 + 0x1c7) = 3;
}
