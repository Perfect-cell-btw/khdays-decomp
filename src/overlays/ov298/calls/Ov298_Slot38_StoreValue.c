/* Actor slot +0x38 callback: stores the value at +0x398. */

void Ov298_Slot38_StoreValue(void *self, int unused, int value)
{
    *(int *)((char *)self + 0x398) = value;
}
