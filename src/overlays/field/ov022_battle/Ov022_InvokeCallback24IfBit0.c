/* Calls the object's callback (+0x24) when its owner's enabled bit (+0x694) is set. */

struct b { unsigned char b0 : 1; };
void Ov022_InvokeCallback24IfBit0(int p)
{
    if (p == 0)
        return;
    if (((struct b *)(*(int *)(p + 8) + 0x694))->b0 == 0)
        return;
    ((void (*)(int))(*(int *)(p + 0x24)))(p);
}
