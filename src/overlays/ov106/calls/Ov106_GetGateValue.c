/* Read the global array (base at data_ov106_020b8b68) at slot param_1, field +0x68. */
extern int data_ov106_020b8b68;
int Ov106_GetGateValue(int param_1) {
    return *(int *)(*(int *)&data_ov106_020b8b68 + param_1 * 4 + 0x68);
}
