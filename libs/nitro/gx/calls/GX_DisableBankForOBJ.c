/* NitroSDK gx (gx_vramcnt.c): GX_DisableBankForOBJ -- disableBankForX_(&gGXState.vramCnt.obj); identified by the state field it passes. */
extern void disableBankForX_(void *p);
extern int data_020446d8;

void GX_DisableBankForOBJ(void) {
    disableBankForX_(&data_020446d8);
}
