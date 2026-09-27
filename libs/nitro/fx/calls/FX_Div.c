/* NitroSDK fx (fx_cp.c): FX_Div -- FX_DivAsync(numer, denom) then FX_GetDivResult(). */
extern void FX_DivAsync(int numer, int denom);
extern int FX_GetDivResult(void);

/* fx32 numer / denom: the divider computes (numer << 32) / denom, and FX_GetDivResult rounds the
 * 64-bit quotient back to fx32 ((q + 0x80000) >> 20). */
int FX_Div(int numer, int denom) {
    FX_DivAsync(numer, denom);
    return FX_GetDivResult();
}
