/* Set the word at +0x4c60 of the ov005 global object to 1. */
extern int data_ov005_0205b810;
void Ov005_SubScene_SetFlagC60(void) {
    *(int *)(data_ov005_0205b810 + 0x4c60) = 1;
}
