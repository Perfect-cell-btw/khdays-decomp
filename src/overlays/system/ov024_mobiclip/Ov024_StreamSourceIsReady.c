/* Report whether the u16 at the second ov024 global object equals 2. */
extern int data_ov024_02093a20;
int Ov024_StreamSourceIsReady(void) {
    return *(unsigned short *)((&data_ov024_02093a20)[1]) == 2;
}
