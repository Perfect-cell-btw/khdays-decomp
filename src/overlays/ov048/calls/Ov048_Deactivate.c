void Ov048_Deactivate(void *unused, void *self)
{
    *(int *)((char *)self + 0x358) = 0;
}
