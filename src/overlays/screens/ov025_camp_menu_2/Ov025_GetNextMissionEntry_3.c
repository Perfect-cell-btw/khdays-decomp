/* Returns the record of an entry of page A's list. */

extern int Ov025_GetPageA();
extern int Ov025_VarTable_GetRecordOfEntry();

int Ov025_GetNextMissionEntry_3(int arg0) {
    return Ov025_VarTable_GetRecordOfEntry(Ov025_GetPageA(arg0) + 0x13fc, arg0);
}
