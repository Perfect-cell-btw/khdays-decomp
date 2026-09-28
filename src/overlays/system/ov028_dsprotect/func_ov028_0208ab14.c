/* Runs the instruction cipher over a block (the same transform as the encryption). */

extern void *Ov028_RC4_EncryptInstructions();
void *func_ov028_0208ab14(unsigned int *ctx, unsigned char *src, unsigned char *dst, unsigned int len) {
    return Ov028_RC4_EncryptInstructions(ctx, src, dst, len);
}
