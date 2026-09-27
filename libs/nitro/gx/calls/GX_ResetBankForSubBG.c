/* NitroSDK gx (gx_vramcnt.c): GX_ResetBankForSubBG -- resetBankForX_(&gGXState.vramCnt.sub_bg); identified by the state field it passes. */
extern void resetBankForX_(void *p);
extern int data_020446e6;

void GX_ResetBankForSubBG(void) {
    resetBankForX_(&data_020446e6);
}
