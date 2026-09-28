/* When the list is idle and Down is pressed alone, selects the next row (wrapping). */

extern int data_0204c18c;
extern void Ov025_ScrollList_SelectRow();

void Ov025_StepForwardIfState8(int arg0) {
    if (*(int *)(arg0 + 0xc) != 0) return;
    if (*(int *)(arg0 + 0x10) != 0) return;
    if ((*(unsigned short *)&data_0204c18c & 0xf0) != 0x80) return;
    int nv = *(int *)(arg0 + 0x2c8) + 1;
    if (nv >= *(int *)(arg0 + 8)) nv = 0;
    if (nv != *(int *)(arg0 + 0x2c8)) Ov025_ScrollList_SelectRow(arg0, nv, 1);
}
