/* Return the 64-bit value stored at data_0204be1c. */

extern int data_0204be1c;

long long Ov025_GetLatchedTick(void) {
    return *(long long *)&data_0204be1c;
}
