/* Stores a callback in a registry node's indexed step slot (the node's step handlers start at +8).
 */

void SetIndexedSlot(int *a, int i, int v)
{
    (a + i)[2] = v;
}
