extern int Ov025_GetCtxBlock968c();
extern int Ov025_SetWord0And20_2();

void Ov025_BindSharedBlockB(int arg0) {
    Ov025_SetWord0And20_2(arg0, Ov025_GetCtxBlock968c());
}
