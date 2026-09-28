/* NitroSystem FND: pushes the block back onto the unit heap's free list. */

void NNS_FndFreeToUnitHeap(int *r0, int *r1)
{
    *r1 = r0[9];
    r0[9] = (int)r1;
}
