extern int Ov025_GetPageA();
extern int Ov025_VarTable_GetRecordOfEntry();

void Ov025_GetNextMissionEntry_3(int arg0) {
    Ov025_VarTable_GetRecordOfEntry(Ov025_GetPageA(arg0) + 0x13fc, arg0);
}
