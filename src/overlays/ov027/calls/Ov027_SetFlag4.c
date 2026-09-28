/* Set bit 2 of the +0x1c flags of the ov027 object. */
extern int data_ov027_02084360;
void Ov027_SetFlag4(void) {
    *(int *)((&data_ov027_02084360)[1] + 0x1c) |= 4;
}
