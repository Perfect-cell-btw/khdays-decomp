/* Copies a record's fields at +6..+0xc and +0x18 into another record; returns the destination. */

int Ov002_CopyRecordFields6to18(int a0, int dst, int src)
{
    *(unsigned short *)(dst + 6) = *(unsigned short *)(src + 6);
    *(unsigned short *)(dst + 8) = *(unsigned short *)(src + 8);
    *(short *)(dst + 0xa) = *(short *)(src + 0xa);
    *(short *)(dst + 0xc) = *(short *)(src + 0xc);
    *(int *)(dst + 0x18) = *(int *)(src + 0x18);
    return dst;
}
