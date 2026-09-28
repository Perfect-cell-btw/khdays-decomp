/* Sets bit `n` of a big-endian bit array (bit 0 is the MSB of word 0). Returns the array.
 *
 * The shift amount has to be written back into the parameter `n` rather than into a
 * fresh local: with a new local mwcc computes the `rsb` in place over `n & 0x1f` and
 * ends up colouring the loaded word / shift / constant one register lower than the
 * ROM does.  Reusing `n` frees r1 for the `mov r1,#1` at the right moment. */
int *BitArray_SetBit(int *bits, int n) {
    int i = n / 32;
    n = 31 - (n & 0x1f);
    bits[i] |= 1 << n;
    return bits;
}
