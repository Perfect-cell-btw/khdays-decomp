/* Sets a flag word of the object to 1. */

void Ov178_SetTimerA000(void *self)
{
    *(int *)((char *)self + 0xc) = 0xa000;
}
