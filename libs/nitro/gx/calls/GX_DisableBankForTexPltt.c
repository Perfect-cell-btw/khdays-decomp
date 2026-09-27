/* NitroSDK gx (gx_vramcnt.c): GX_DisableBankForTexPltt -- disableBankForX_(&gGXState.vramCnt.texPltt); identified by the state field it passes. */
extern void disableBankForX_(void *p);
extern int data_020446de;

void GX_DisableBankForTexPltt(void) {
    disableBankForX_(&data_020446de);
}
