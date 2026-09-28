extern int Ov025_GetDescriptor0();
extern void Ov025_SetWord0And20();
extern int Ov025_GetDescriptor2();
extern void Ov025_ClampValueToLimitAndNotify();

void Ov025_SetupAndConfigure(int *arg0, int arg1, int arg2) {
    Ov025_SetWord0And20(arg0, Ov025_GetDescriptor0());
    Ov025_ClampValueToLimitAndNotify(arg0, arg1, arg2, Ov025_GetDescriptor2());
}
