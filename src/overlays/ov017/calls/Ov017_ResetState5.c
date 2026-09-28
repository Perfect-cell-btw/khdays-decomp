void Ov017_ResetState5(void *self)
{
    *(unsigned char *)((char *)self + 0x1b4) = 5;
    *(int *)((char *)self + 0x1b0) = 0;
}
