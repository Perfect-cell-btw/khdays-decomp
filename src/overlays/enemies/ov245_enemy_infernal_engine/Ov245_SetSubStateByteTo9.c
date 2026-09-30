/* Queues action 9. */

void Ov245_SetSubStateByteTo9(int *p)
{
    *(char *)(*p + 0x1c7) = 9;
}
