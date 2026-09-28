/* Return the address (*(&data+4)) + 0x9500. */
extern int data_ov009_020563e4;
int Ov009_GetCtxBlock9500(void) {
    return *(int *)((char *)&data_ov009_020563e4 + 4) + 0x9500;
}
