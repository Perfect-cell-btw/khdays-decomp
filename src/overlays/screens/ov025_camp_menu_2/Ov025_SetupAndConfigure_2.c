/* Initialises a value record from its descriptors and clamps its value to the limit (second
 * variant). */

extern int Ov025_GetDescriptor0();
extern void Ov025_SetWord0And20_2();
extern int Ov025_GetDescriptor2();
extern void Ov025_ClampValueToLimitAndNotify_2();

void Ov025_SetupAndConfigure_2(int *arg0, int arg1, int arg2) {
    Ov025_SetWord0And20_2(arg0, Ov025_GetDescriptor0());
    Ov025_ClampValueToLimitAndNotify_2(arg0, arg1, arg2, Ov025_GetDescriptor2());
}
