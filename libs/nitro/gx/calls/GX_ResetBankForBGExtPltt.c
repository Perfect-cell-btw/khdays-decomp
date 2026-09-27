/* NitroSDK gx (gx_vramcnt.c): GX_ResetBankForBGExtPltt -- resetBankForX_(&gGXState.vramCnt.bgExtPltt), after clearing the DISPCNT ext-palette enable (bit 30); identified by the state field it passes. */
extern void *resetBankForX_();
extern unsigned short data_020446e2;

void *GX_ResetBankForBGExtPltt(void) {
    volatile unsigned int *dispcnt = (volatile unsigned int *)0x4000000;
    *dispcnt = *dispcnt & ~0x40000000;
    return resetBankForX_(&data_020446e2);
}
