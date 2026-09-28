void Ov298_Slot38_StoreValue(void *self, int unused, int value)
{
    *(int *)((char *)self + 0x398) = value;
}
