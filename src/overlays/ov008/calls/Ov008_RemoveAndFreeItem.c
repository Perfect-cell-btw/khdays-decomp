/* Removes the item from the context list and frees it with its buffer. */

extern void NNS_FndRemoveListObject(void *list, void *object);
extern void NNSi_FndFreeFromDefaultHeap(void *block);

void Ov008_RemoveAndFreeItem(void *context, void *object)
{
    NNS_FndRemoveListObject((char *)context + 0x1cc, object);
    NNSi_FndFreeFromDefaultHeap(*(void **)((char *)object + 0x14));
    NNSi_FndFreeFromDefaultHeap(object);
}
