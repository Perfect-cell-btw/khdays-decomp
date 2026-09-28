extern int data_ov023_0208a784;
/* Store value at +0x875d8 of the index-th slot of the ov023 table. */
void Ov023_SetScriptSlotWord(int param_1, int param_2) {
    *(int *)((&data_ov023_0208a784)[1] + param_2 * 4 + 0x875d8) = param_1;
}
