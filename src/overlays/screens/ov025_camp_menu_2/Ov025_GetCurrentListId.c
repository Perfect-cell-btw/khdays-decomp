/* Id of the menu context's current list. Returns the list's id. */

extern int Ov025_GetPageA();
extern unsigned short Ov025_GetId10();

int Ov025_GetCurrentListId(int arg0) {
    return Ov025_GetId10(Ov025_GetPageA(arg0) + 0x13fc);
}
