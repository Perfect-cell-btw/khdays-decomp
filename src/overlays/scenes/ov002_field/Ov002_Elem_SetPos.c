extern int Ov002_Elem_SetX();
extern int Ov002_Elem_SetY();

void Ov002_Elem_SetPos(int arg0, int arg1, int arg2, int arg3) {
    Ov002_Elem_SetX(arg0, arg1, arg2, arg3);
    Ov002_Elem_SetY(arg0, arg1, arg3);
}
