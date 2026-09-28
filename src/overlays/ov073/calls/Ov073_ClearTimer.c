void Ov073_ClearTimer(void *unused, void *self)
{
    *(int *)((char *)self + 0x24) = 0;
}
