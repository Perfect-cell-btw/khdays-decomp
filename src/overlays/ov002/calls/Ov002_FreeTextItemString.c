/* Frees the item's string copy, tail-jumping through the default heap's free entry
 * (NNSi_FndFreeFromDefaultHeap). */

extern void NNSi_FndFreeFromDefaultHeap();

void Ov002_FreeTextItemString(int arg0) {
    NNSi_FndFreeFromDefaultHeap(*(int *)(arg0 + 0x1c));
}
