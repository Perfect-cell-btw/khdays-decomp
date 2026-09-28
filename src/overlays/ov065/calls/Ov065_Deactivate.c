void Ov065_Deactivate(void *unused, void *self)
{
    *(int *)((char *)self + 0x110) = 0;
}
