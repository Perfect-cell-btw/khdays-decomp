/* Marks the shot finished (state 4) with a 0x3000 linger time; returns 0. */

int Ov039_SetMode4Delay3000(void *unused, void *self)
{
    *(unsigned char *)((char *)self + 2) = 4;
    *(int *)((char *)self + 4) = 0x3000;
    return 0;
}
