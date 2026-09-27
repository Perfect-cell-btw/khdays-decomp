/* NitroSDK gx (gx_vramcnt.c): GX_DisableBankForSubBG -- disableBankForX_(&gGXState.vramCnt.sub_bg); identified by the state field it passes. */
extern void disableBankForX_(void *p);
extern int data_020446e6;

void GX_DisableBankForSubBG(void) {
    disableBankForX_(&data_020446e6);
}
