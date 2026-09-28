/* Binds the object to the shared block (+0x968c). */

extern int Ov025_GetCtxBlock968c();
extern int Ov025_SetWord0And20();

void Ov025_BindSharedBlock(int arg0) {
    Ov025_SetWord0And20(arg0, Ov025_GetCtxBlock968c());
}
