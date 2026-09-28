extern void FX_DivAsync(int num, int denom);

/* Kick an async divide, spin on DIVCNT busy, return the 64-bit DIV_RESULT. */
long long FX_DivFx64c(int num, int denom)
{
    volatile unsigned short *reg_divcnt = (volatile unsigned short *)0x04000280;
    FX_DivAsync(num, denom);
    while (*reg_divcnt & 0x8000) {
    }
    return *(long long *)0x040002a0;
}
