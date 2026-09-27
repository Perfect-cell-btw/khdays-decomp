/* NitroSDK gx (gx_vramcnt.c): GX_ResetBankForTex -- resetBankForX_(&gGXState.vramCnt.tex); identified by the state field it passes. */
extern void resetBankForX_(void *p);
extern int data_020446dc;

void GX_ResetBankForTex(void) {
    resetBankForX_(&data_020446dc);
}
