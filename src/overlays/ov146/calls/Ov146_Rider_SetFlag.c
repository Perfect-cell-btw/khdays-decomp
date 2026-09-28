/* Stores whether the flag is nonzero at +0x18. */

/* Store a boolean at +0x18. */
void Ov146_Rider_SetFlag(int param_1, int param_2) {
    *(signed char *)(param_1 + 0x18) = param_2 != 0;
}
