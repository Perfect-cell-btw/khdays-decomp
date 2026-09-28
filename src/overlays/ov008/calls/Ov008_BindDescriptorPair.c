extern int Ov008_GetDescriptor0(void);
extern int Ov008_SetWord0And20(int arg0, int arg1);
extern int Ov008_GetDescriptor2(void);
extern void Ov008_ClampValueToLimitAndNotify(int arg0, int arg1, int arg2, int arg3);

void Ov008_BindDescriptorPair(int arg0, int arg1, int arg2)
{
    Ov008_SetWord0And20(arg0, Ov008_GetDescriptor0());
    Ov008_ClampValueToLimitAndNotify(arg0, arg1, arg2, Ov008_GetDescriptor2());
}
