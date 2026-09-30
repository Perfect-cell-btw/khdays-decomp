/* Sets a flag word of the object to 1. */

void Ov124_Slot38_SetFlag3C8(void *self)
{
    *(int *)((char *)self + 0x3c8) = 1;
}
