/* Sets the active flag, clears the timer and stores the value. */

void Ov035_ArmWithValue(void *self, int value)
{
    *(int *)self = 1;
    *(int *)((char *)self + 0x10c) = 0;
    *(int *)((char *)self + 0x110) = value;
}
