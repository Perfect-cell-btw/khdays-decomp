/* Returns the address of the entry's payload (+0x1c) when the low nibble of its byte at +0x40 is
 * set, otherwise 0. */

int Ov002_AddrOf0x1cIfLowNibbleSet(int p)
{
    return (*(signed char *)(p + 0x40) & 0xf) != 0 ? p + 0x1c : 0;
}
