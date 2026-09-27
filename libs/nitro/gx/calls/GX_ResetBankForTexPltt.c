/* NitroSDK gx (gx_vramcnt.c): GX_ResetBankForTexPltt -- resetBankForX_(&gGXState.vramCnt.texPltt); identified by the state field it passes. */
extern void resetBankForX_(void *p);
extern int data_020446de;

void GX_ResetBankForTexPltt(void) {
    resetBankForX_(&data_020446de);
}
