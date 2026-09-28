/* NitroSDK gx (gx_vramcnt.c): GX_ResetBankForTex -- resetBankForX_(&gGXState.vramCnt.tex);
 * identified by the state field it passes. Returns the banks that were assigned to textures. */
extern int resetBankForX_(void *p);
extern int data_020446dc;

int GX_ResetBankForTex(void) {
    return resetBankForX_(&data_020446dc);
}
