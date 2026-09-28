/* Finds an entry by id in page A's list. Returns the object, or NULL. */

extern int Ov025_GetPageA();
extern int Ov025_FindListObjectById();

void *Ov025_GetNextMissionEntry_5(int arg0) {
    return Ov025_FindListObjectById(Ov025_GetPageA(arg0) + 0x13fc, arg0);
}
