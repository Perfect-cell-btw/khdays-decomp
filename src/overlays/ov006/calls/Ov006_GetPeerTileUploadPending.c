/* Read the +0x30 word of element param of the ov006 global array. */
extern int data_ov006_020565e4;
int Ov006_GetPeerTileUploadPending(int param_1) {
    return *(int *)(data_ov006_020565e4 + param_1 * 4 + 0x30);
}
