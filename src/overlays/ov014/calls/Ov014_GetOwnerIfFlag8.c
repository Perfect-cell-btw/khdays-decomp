/* Returns the owner (+0x28) while +0x12 bit 3 is set, else 0. */

void *Ov014_GetOwnerIfFlag8(void *self)
{
    if (*(unsigned short *)((char *)self + 0x12) & 8) {
        return *(void **)((char *)self + 0x28);
    }
    return 0;
}
