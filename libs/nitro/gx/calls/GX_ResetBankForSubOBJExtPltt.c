/* NitroSDK gx (gx_vramcnt.c): GX_ResetBankForSubOBJExtPltt -- resetBankForX_(&gGXState.vramCnt.sub_objExtPltt), after clearing the sub-DISPCNT ext-palette enable (bit 31); identified by the state field it passes. */
extern void *resetBankForX_();
extern unsigned short data_020446ec;

void *GX_ResetBankForSubOBJExtPltt(void) {
    volatile unsigned int *dispcnt = (volatile unsigned int *)0x4001000;
    *dispcnt = *dispcnt & ~0x80000000u;
    return resetBankForX_(&data_020446ec);
}
