/* Stores the negation of the value into a field of the camp-menu context. */

extern int data_ov025_020b5744;

void Ov025_SetCtxField962c(int arg0) {
    *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x962c) = arg0 == 0;
}
