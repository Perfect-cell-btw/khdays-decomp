/* Sets both coordinates of the element's position. */

extern void Ov005_Elem_SetX(int a, int b, int c, int d);
extern void Ov005_Elem_SetY(int a, int b, int d);
void Ov005_Elem_SetPos(int param_1, int param_2, int param_3, int param_4) {
    Ov005_Elem_SetX(param_1, param_2, param_3, param_4);
    Ov005_Elem_SetY(param_1, param_2, param_4);
}
