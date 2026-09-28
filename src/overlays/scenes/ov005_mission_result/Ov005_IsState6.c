/* Report whether +0x4bf0 of the ov005 global object equals 6. */
extern int data_ov005_0205b80c;
int Ov005_IsState6(void) {
    return *(int *)(data_ov005_0205b80c + 0x4bf0) == 6;
}
