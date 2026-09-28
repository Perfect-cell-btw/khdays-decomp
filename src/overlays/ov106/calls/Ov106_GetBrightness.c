/* Read the far field at +0x8e3c of the ov106 global object. */
extern int data_ov106_020b8b60;
int Ov106_GetBrightness(void) {
    return *(int *)(data_ov106_020b8b60 + 0x8e3c);
}
