/* Runs the callback of the current context mode, if any. */

extern int Ov025_GetCtxField95cc();
extern int data_ov025_020b37e0;

void Ov025_RunModeCallback(void) {
    int (*f)(void) = ((int (**)(void))&data_ov025_020b37e0)[Ov025_GetCtxField95cc()];
    if (f != 0) {
        f();
    }
}
