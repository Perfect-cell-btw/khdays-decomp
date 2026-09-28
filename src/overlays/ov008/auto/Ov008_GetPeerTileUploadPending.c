extern char *data_ov008_02090f24;
int Ov008_GetPeerTileUploadPending(int index)
{
    return *(int *)(data_ov008_02090f24 + 0x30 + index * 4);
}
