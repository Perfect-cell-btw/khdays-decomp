/* Actor slot +0x38 callback: stores the value at +0x390. */


void Ov299_Slot38_StoreValue(void *self, void *unused, int *src)
{
    *(int *)((char *)self + 0x390) = *src;
}
