/* Store param_2 into the field at param_1+0x1a34. */
void Ov023_Window_SetField1A34(int param_1, int param_2) {
    *(int *)(param_1 + 0x1a34) = param_2;
}
