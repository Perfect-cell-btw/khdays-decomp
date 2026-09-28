/* Whether the actor's hit points (+0x21a) are below a tenth of its maximum (+0x218). */

int Ov266_IsField21aBelowField218Div10(int *obj)
{
    int base = *obj;
    return *(short *)(base + 0x21a) < *(short *)(base + 0x218) / 10;
}
