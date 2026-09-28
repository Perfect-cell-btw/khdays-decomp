/* Forward the table entry *(global+4)[param_1] + 0x17c (and param_2) to the handler. */
extern int Ov002_MulTagAtField4ePlusField54(int entry, int arg);
extern int data_ov002_0207fa20;

int Ov002_List_ScaleEntryTag(int param_1, int param_2) {
    return Ov002_MulTagAtField4ePlusField54(*(int *)(*(int *)((char *)&data_ov002_0207fa20 + 4) + param_1 * 4 + 0x17c), param_2);
}
