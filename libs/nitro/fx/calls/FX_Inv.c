/* NitroSDK fx (fx_cp.c): FX_Inv -- FX_InvAsync(denom) then FX_GetDivResult(). */
extern void FX_InvAsync(int x);
extern int FX_GetDivResult(void);

int FX_Inv(int x) {
    FX_InvAsync(x);
    return FX_GetDivResult();
}
