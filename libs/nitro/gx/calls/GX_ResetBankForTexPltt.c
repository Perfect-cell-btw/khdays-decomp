/* NitroSDK gx (gx_vramcnt.c): GX_ResetBankForTexPltt -- resetBankForX_(&gGXState.vramCnt.texPltt);
 * identified by the state field it passes. Returns the banks that were assigned to texture
 * palettes. */
extern int resetBankForX_(void *p);
extern int data_020446de;

int GX_ResetBankForTexPltt(void) {
    return resetBankForX_(&data_020446de);
}
