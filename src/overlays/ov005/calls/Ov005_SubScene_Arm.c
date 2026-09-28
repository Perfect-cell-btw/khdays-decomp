/* Set the word at +0x4b7c of the ov005 global object to 1. */
extern int data_ov005_0205b810;
void Ov005_SubScene_Arm(void) {
    *(int *)(data_ov005_0205b810 + 0x4b7c) = 1;
}
