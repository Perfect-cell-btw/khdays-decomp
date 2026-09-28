/* Removes the block from the object's list and frees it. */

extern void NNS_FndRemoveListObject(char *, void *);
extern void NNSi_FndFreeFromDefaultHeap(void *);
void Ov008_RemoveAndFreeBlock(char *obj, void *block)
{
    NNS_FndRemoveListObject(obj + 0x1e7c, block);
    if (block != 0) {
        NNSi_FndFreeFromDefaultHeap(block);
    }
}
