/* Stores a callback in a registry node's indexed step slot (the node's step handlers start at +8).
 * Returns a + i, which the ROM leaves in r0: AI steps that end by tail-calling this return it as
 * their (non-zero) result. */

int *SetIndexedSlot(int *a, int i, int v)
{
    a += i;
    a[2] = v;
    return a;
}
