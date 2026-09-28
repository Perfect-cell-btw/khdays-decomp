/* Binds the object to canned descriptor 0. */

extern int Ov008_GetDescriptor0(void);
extern void Ov008_SetWord0And20_2(void *, int);
void Ov008_BindDescriptor0B(void *obj)
{
    Ov008_SetWord0And20_2(obj, Ov008_GetDescriptor0());
}
