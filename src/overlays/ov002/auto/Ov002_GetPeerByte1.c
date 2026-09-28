/* Byte +1 of the current peer record (0xff when none). */

extern int data_ov002_0207fa10;

int Ov002_GetPeerByte1(void) {
    int p = *(int *)(*(int *)&data_ov002_0207fa10 + 4);
    if (p == 0) {
        return 0xff;
    }
    return *(unsigned char *)(p + 1);
}
