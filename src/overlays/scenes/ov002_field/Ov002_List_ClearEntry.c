/* Clears an entry of the list table (+0x17c). */

extern int data_ov002_0207fa20;

void Ov002_List_ClearEntry(int arg0) {
    *(int *)(*(int *)((char *)&data_ov002_0207fa20 + 4) + arg0 * 4 + 0x17c) = 0;
}
