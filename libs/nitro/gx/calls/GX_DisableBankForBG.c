/* NitroSDK gx (gx_vramcnt.c): GX_DisableBankForBG -- disableBankForX_(&gGXState.vramCnt.bg); identified by the state field it passes. */
extern void disableBankForX_(void *p);
extern int data_020446d6;

void GX_DisableBankForBG(void) {
    disableBankForX_(&data_020446d6);
}
