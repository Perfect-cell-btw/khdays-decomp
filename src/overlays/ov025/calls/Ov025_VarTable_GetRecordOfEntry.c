extern int Ov025_GetVarRecordByIndex();

int Ov025_VarTable_GetRecordOfEntry(int arg0, int arg1) {
    return Ov025_GetVarRecordByIndex(arg0, *(unsigned short *)(arg1 + 4));
}
