/* Report whether +0x8be8 of the second ov024 global object is >= 0x10. */
extern int data_ov024_02093a20;
int Ov024_MobiClip_PlayerPollAbort(void) {
    return *(int *)((&data_ov024_02093a20)[1] + 0x8be8) >= 0x10;
}
