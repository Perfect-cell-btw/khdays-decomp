/* Sets the style of a slot table entry. */

extern void Obj_SetField14_2(int, int);

void SlotTable_SetEntryStyle(void *pArg1, int param_2, int param_3) {
    int param_1 = (int)pArg1;
    char *elem = (char *)(param_1 + 4) + param_2 * 0x8c;
    if (param_2 < 0) {
        return;
    }
    Obj_SetField14_2((int)(elem + 0x14), param_3);
}
