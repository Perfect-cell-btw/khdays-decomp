int Ov014_IsState3(void *self)
{
    return *(signed char *)((char *)self + 0x134) == 3;
}
