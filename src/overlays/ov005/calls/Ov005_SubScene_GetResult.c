/* Read the word at +0x4b78 of the ov005 global object. */
extern int data_ov005_0205b810;
int Ov005_SubScene_GetResult(void) {
    return *(int *)(data_ov005_0205b810 + 0x4b78);
}
