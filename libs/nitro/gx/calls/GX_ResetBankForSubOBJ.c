/* NitroSDK gx (gx_vramcnt.c): GX_ResetBankForSubOBJ -- resetBankForX_(&gGXState.vramCnt.sub_obj); identified by the state field it passes. */
extern void resetBankForX_(void *p);
extern int data_020446e8;

void GX_ResetBankForSubOBJ(void) {
    resetBankForX_(&data_020446e8);
}
