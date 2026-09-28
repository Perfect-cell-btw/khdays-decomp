/* Returns the first word of the list at UI context +0x94. */

extern int data_ov002_0207f60c;

int Ov002_Ui_GetListHead(void) {
    return *(int *)(*(int *)(*(int *)&data_ov002_0207f60c + 0x94));
}
