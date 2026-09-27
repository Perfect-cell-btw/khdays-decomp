/* NitroSDK gx (gx_vramcnt.c): GX_DisableBankForTex -- disableBankForX_(&gGXState.vramCnt.tex); identified by the state field it passes. */
extern void disableBankForX_(void *p);
extern int data_020446dc;

void GX_DisableBankForTex(void) {
    disableBankForX_(&data_020446dc);
}
