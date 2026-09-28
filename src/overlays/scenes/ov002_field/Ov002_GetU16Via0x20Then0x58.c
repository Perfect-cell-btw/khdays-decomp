/* Returns the low halfword of the attached object's word at +0x58. */

int Ov002_GetU16Via0x20Then0x58(int p)
{
    return (unsigned short)*(int *)(*(int *)(p + 0x20) + 0x58);
}
