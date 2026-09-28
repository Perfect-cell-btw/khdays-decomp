/* Report whether +0x4b74 of the ov005 global object is <= 1. */
extern int data_ov005_0205b810;
int Ov005_SubScene_IsIdle(void) {
    return *(int *)(data_ov005_0205b810 + 0x4b74) <= 1;
}
