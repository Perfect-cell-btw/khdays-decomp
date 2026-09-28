/* Page B's busy word when active, else 0. */

extern int Ov025_GetPageB();
extern int data_ov025_020b575c;

int Ov025_PageB_GetBusy(int arg0) {
    int x = Ov025_GetPageB(arg0);
    return data_ov025_020b575c != 0 ? *(int *)(x + 8) : 0;
}
