extern int Ov025_GetPageA();
extern int Ov025_GetId10();

void Ov025_GetCurrentListId(int arg0) {
    Ov025_GetId10(Ov025_GetPageA(arg0) + 0x13fc);
}
