/* Returns the record count (+0x10). */

unsigned short Ov302_GetId10(void *self)
{
    return *(unsigned short *)((char *)self + 0x10);
}
