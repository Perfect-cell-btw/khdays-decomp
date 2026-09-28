/* Clears bit `n` of a big-endian bit array (bit 0 is the MSB of word 0).
 * Same shift-amount-into-`n` requirement as BitArray_SetBit. */
void BitArray_ClearBit(int *bits, int n) {
    int i = n / 32;
    n = 31 - (n & 0x1f);
    bits[i] &= ~(1 << n);
}
