/* Finds the next entry after the value with a zero count in page A's list. */

extern int Ov025_GetPageA();
extern int Ov025_FindListObjectWithField10Zero();

void Ov025_GetNextMissionEntry(int arg0) {
    Ov025_FindListObjectWithField10Zero(Ov025_GetPageA(arg0) + 0x13fc, arg0);
}
