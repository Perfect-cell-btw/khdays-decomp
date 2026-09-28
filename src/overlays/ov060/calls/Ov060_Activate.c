/* Sets the active flag and clears the timer. */

void Ov060_Activate(void *self)
{
    *(int *)self = 1;
    *(int *)((char *)self + 0x10c) = 0;
}
