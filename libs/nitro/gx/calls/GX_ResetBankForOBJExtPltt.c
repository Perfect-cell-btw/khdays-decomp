/* NitroSDK gx (gx_vramcnt.c): GX_ResetBankForOBJExtPltt -- resetBankForX_(&gGXState.vramCnt.objExtPltt), after clearing the DISPCNT ext-palette enable (bit 31); identified by the state field it passes. */
extern void *resetBankForX_();
extern unsigned short data_020446e4;

void *GX_ResetBankForOBJExtPltt(void) {
    volatile unsigned int *dispcnt = (volatile unsigned int *)0x4000000;
    *dispcnt = *dispcnt & ~0x80000000;
    return resetBankForX_(&data_020446e4);
}
