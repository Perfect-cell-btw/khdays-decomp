/* Binds the object to canned descriptor 0. */

extern int Ov025_GetDescriptor0();
extern int Ov025_SetWord0And20();

void Ov025_BindDescriptor0(int arg0) {
    Ov025_SetWord0And20(arg0, Ov025_GetDescriptor0());
}
