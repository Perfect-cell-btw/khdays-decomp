extern void Ov008_Elem_SetX(void *, void *, int, int);
extern void Ov008_Elem_SetY(void *, void *, int);
void Ov008_Elem_SetPos(void *arg0, void *arg1, int arg2, int arg3)
{
    Ov008_Elem_SetX(arg0, arg1, arg2, arg3);
    Ov008_Elem_SetY(arg0, arg1, arg3);
}
