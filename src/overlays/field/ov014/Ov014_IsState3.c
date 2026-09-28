/* Whether the state byte (+0x134) is 3. */

int Ov014_IsState3(void *self)
{
    return *(signed char *)((char *)self + 0x134) == 3;
}
