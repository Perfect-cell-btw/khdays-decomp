/* Stores an indexed byte of the menu state (+0x9751). */

extern int data_ov008_02090f04[];
void Ov008_SetCtxByte9751(int offset, int value)
{
    *(unsigned char *)(data_ov008_02090f04[1] + offset + 0x9751) = value;
}
