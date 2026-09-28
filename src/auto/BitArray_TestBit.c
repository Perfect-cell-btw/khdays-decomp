/* Tests bit `n` of a big-endian bit array (bit 0 is the MSB of word 0); returns the
 * masked word, not a 0/1 flag.  Companion of BitArray_SetBit (set) and BitArray_ClearBit
 * (clear), and it needs the same shift-amount-into-`n` spelling to colour the
 * temporaries the way the ROM does. */
int BitArray_TestBit(int *bits, int n) {
    int i = n / 32;
    n = 31 - (n & 0x1f);
    return bits[i] & (1 << n);
}
