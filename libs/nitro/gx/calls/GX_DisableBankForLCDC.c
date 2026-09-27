/* NitroSDK gx (gx_vramcnt.c): GX_DisableBankForLCDC -- disableBankForX_(&gGXState.vramCnt.lcdc); identified by the state field it passes. */
extern void disableBankForX_(void *p);
extern int data_020446d4;

void GX_DisableBankForLCDC(void) {
    disableBankForX_(&data_020446d4);
}
