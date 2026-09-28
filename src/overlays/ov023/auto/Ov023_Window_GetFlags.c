/* Read the field at param_1+0x1a28. */
int Ov023_Window_GetFlags(int param_1) {
    return *(int *)(param_1 + 0x1a28);
}
