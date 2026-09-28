/* Finds an entry by id in page A's list. */

extern int Ov025_GetPageA();
extern int Ov025_FindListObjectById();

void Ov025_GetNextMissionEntry_5(int arg0) {
    Ov025_FindListObjectById(Ov025_GetPageA(arg0) + 0x13fc, arg0);
}
