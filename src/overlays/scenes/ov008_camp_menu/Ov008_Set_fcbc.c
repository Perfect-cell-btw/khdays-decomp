/* Frees the object's buffer at +0x58 when set and clears the pointer. */

extern void NNSi_FndFreeFromDefaultHeap(void *block);

void Ov008_Set_fcbc(void *object)
{
    void *block = *(void **)((char *)object + 0x58);

    if (block != 0) {
        NNSi_FndFreeFromDefaultHeap(block);
        *(int *)((char *)object + 0x58) = 0;
    }
}
