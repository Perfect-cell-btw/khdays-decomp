/* Binds descriptor 0 and sets the object's layout from descriptor 2. */

extern int Ov008_GetDescriptor0(void);
extern int Ov008_SetWord0And20_2(int arg0, int arg1);
extern int Ov008_GetDescriptor2(void);
extern void Ov008_ClampTextPosToLimitAndNotify(int arg0, int arg1, int arg2, int arg3);

void Ov008_BindDescriptorPairB(int arg0, int arg1, int arg2)
{
    Ov008_SetWord0And20_2(arg0, Ov008_GetDescriptor0());
    Ov008_ClampTextPosToLimitAndNotify(arg0, arg1, arg2, Ov008_GetDescriptor2());
}
