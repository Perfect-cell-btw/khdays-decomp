/* NitroSDK gx (gx_vramcnt.c): GX_DisableBankForSubOBJ -- disableBankForX_(&gGXState.vramCnt.sub_obj); identified by the state field it passes. */
extern void disableBankForX_(void *p);
extern int data_020446e8;

void GX_DisableBankForSubOBJ(void) {
    disableBankForX_(&data_020446e8);
}
