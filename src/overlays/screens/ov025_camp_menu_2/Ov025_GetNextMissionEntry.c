/* Finds the next entry after the value with a zero count in page A's list. Returns the entry, or
 * NULL. */

extern int Ov025_GetPageA();
extern int Ov025_FindListObjectWithField10Zero();

void *Ov025_GetNextMissionEntry(int arg0) {
    return Ov025_FindListObjectWithField10Zero(Ov025_GetPageA(arg0) + 0x13fc, arg0);
}
