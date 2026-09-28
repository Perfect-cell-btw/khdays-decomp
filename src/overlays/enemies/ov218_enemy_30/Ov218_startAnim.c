/* Tail-call Ov107_StartAnim with the handle at param_1+0x3ac, param_2 and flag 1. */
extern int Ov107_StartAnim(int handle, int b, int c);
int Ov218_startAnim(int param_1, int param_2) {
    return Ov107_StartAnim(*(int *)(param_1 + 0x3ac), param_2, 1);
}
