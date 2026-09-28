int Ov291_OnHitStore(void *self, int value)
{
    *(int *)((char *)*(void **)((char *)self + 0x214) + 0x2c) = value;
    return 1;
}
