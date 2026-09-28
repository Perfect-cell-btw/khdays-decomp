/* Returns the node (+0x1c) while +0x12 bit 3 is set, else 0. */

void *Ov014_GetNodeIfFlag8(void *self)
{
    if (*(unsigned short *)((char *)self + 0x12) & 8) {
        return (char *)self + 0x1c;
    }
    return 0;
}
