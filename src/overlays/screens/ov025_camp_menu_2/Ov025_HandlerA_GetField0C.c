/* Returns the word at +0xc of the current handler's object. */

extern int data_ov025_020b574c;
extern int data_ov025_020b4ab0;

int Ov025_HandlerA_GetField0C(void) {
    return *(int *)(*(int *)((char *)&data_ov025_020b4ab0 + *(int *)&data_ov025_020b574c * 8) + 0xc);
}
