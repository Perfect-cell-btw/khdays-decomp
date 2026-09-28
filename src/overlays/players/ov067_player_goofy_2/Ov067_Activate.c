void Ov067_Activate(void *unused, void *self)
{
    *(int *)((char *)self + 0x35c) = 0;
    *(int *)((char *)self + 0x358) = 1;
}
