/* NitroSDK gx (gx_vramcnt.c): GX_DisableBankForSubOBJExtPltt -- disableBankForX_(&gGXState.vramCnt.sub_objExtPltt), after clearing the sub-DISPCNT ext-palette enable (bit 31); identified by the state field it passes. */
extern void *disableBankForX_();
extern unsigned short data_020446ec;

void *GX_DisableBankForSubOBJExtPltt(void) {
    volatile unsigned int *dispcnt = (volatile unsigned int *)0x4001000;
    *dispcnt = *dispcnt & ~0x80000000u;
    return disableBankForX_(&data_020446ec);
}
