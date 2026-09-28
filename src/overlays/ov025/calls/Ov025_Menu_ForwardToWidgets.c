extern int Ov025_GetPageA();
extern int func_ov025_0208eb08();

void Ov025_Menu_ForwardToWidgets(int arg0, int arg1, int arg2) {
    func_ov025_0208eb08(Ov025_GetPageA(arg0) + 4, arg0, arg1, arg2);
}
