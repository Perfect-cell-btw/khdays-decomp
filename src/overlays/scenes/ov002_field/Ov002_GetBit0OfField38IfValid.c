/* Returns bit 0 of the attached object's flags (+0x38), or 0 when the handle is -1 or has no
 * object. */

int Ov002_GetBit0OfField38IfValid(int p)
{
    if (p == -1)
        return 0;
    if (*(int *)(p + 0x20) != 0)
        return *(int *)(*(int *)(p + 0x20) + 0x38) & 1;
    return 0;
}
