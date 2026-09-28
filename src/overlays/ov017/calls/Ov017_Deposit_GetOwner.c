void *Ov017_Deposit_GetOwner(void *self)
{
    return *(void **)((char *)*(void **)((char *)self + 8) + 0x88);
}
