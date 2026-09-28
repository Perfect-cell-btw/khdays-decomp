/* Tail-call Ov107_StartAnim with the handle at param_1+0x414, param_2 and flag 0. */
extern int Ov107_StartAnim(int handle, int b, int c);
int Ov227_startAnim(int param_1, int param_2) {
    return Ov107_StartAnim(*(int *)(param_1 + 0x414), param_2, 0);
}
