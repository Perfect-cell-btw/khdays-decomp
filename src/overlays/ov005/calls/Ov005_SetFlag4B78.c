/* Set the word at +0x4b78 of the ov005 global object to 1. */
extern int data_ov005_0205b810;
void Ov005_SetFlag4B78(void) {
    *(int *)(data_ov005_0205b810 + 0x4b78) = 1;
}
