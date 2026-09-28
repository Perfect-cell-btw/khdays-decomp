void Ov046_Activate(void *unused, void *self)
{
    *(int *)((char *)self + 0x114) = 0;
    *(int *)((char *)self + 0x110) = 1;
}
