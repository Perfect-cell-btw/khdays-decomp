/* Return the address of the block at +0x2c of the second argument. The first argument is accepted
 * and ignored -- eight bytes of code, so this is a signature-compatible accessor, not a stub. */

int Ov008_GetEntryBlock2c(int a, int b) {
	return b + 0x2c;
}
