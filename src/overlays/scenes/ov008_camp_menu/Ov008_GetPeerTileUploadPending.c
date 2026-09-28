/* Read the +0x30 word of element param of the ov008 global array. */

extern char *data_ov008_02090f24;
int Ov008_GetPeerTileUploadPending(int index)
{
    return *(int *)(data_ov008_02090f24 + 0x30 + index * 4);
}
