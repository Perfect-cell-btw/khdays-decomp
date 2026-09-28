/* Clear the global word at data_ov107_020cbb00. */
extern int data_ov107_020cbb00;
void Ov107_ClearGlobalCBB00(void) {
    *(int *)&data_ov107_020cbb00 = 0;
}
