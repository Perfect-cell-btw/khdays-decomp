/* First canned descriptor of the screen work area (+0x9680). */

extern int data_ov025_020b5744;

int Ov025_GetDescriptor0(void) {
    return *(int *)((char *)&data_ov025_020b5744 + 4) + 0x9680;
}
