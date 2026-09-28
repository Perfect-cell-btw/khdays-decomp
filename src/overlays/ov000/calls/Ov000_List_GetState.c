/* Read the s16 at +0x966a of the ov000 global object. */
extern int data_ov000_0205ac3c;
int Ov000_List_GetState(void) {
    return *(short *)(data_ov000_0205ac3c + 0x966a);
}
