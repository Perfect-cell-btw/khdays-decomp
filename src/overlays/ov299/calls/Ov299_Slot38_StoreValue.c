
void Ov299_Slot38_StoreValue(void *self, void *unused, int *src)
{
    *(int *)((char *)self + 0x390) = *src;
}
