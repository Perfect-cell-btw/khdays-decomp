/* Sets the active flag, clears the timer and stores the value. */

void Ov040_ArmWithValue(void *self, int value)
{
    *(int *)self = 1;
    *(int *)((char *)self + 0x110) = 0;
    *(int *)((char *)self + 0x114) = value;
}
