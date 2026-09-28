/* Stores the value clamped to 0..16 into the object's field at +0x4628. */

void ClampToRange0to16At0x4628(int p, int v)
{
    if (v > 0x10)
        v = 0x10;
    else if (v < 0)
        v = 0;
    *(int *)(p + 0x4628) = v;
}
