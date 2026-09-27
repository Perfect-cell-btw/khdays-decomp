/* NitroSDK fx (fx_cp.c): FX_Div -- FX_DivAsync(numer, denom) then FX_GetDivResult(). */
extern void FX_DivAsync(int x);
extern int FX_GetDivResult(void);

int FX_Div(int x) {
    FX_DivAsync(x);
    return FX_GetDivResult();
}
