/* Whether the local player is the host or has been marked ready in the setup context. */

extern int data_ov022_020b2e78;
extern short Session_GetLocalPlayerIndex(void);
unsigned int func_ov022_02088338(void) {
    int p = ((int *)&data_ov022_020b2e78)[1];
    if (p == 0) return 0;
    if (Session_GetLocalPlayerIndex() == 0) return 1;
    return ((unsigned int)*(unsigned char *)(p + 0x3c) << 0x1c) >> 0x1f;
}
