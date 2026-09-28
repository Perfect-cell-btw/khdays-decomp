void Ov180_SetTimerA000(void *self)
{
    *(int *)((char *)self + 0xc) = 0xa000;
}
