/* NitroSDK spi (tp.c): TP_GetLatestIndexInAuto -- returns tpState.index (+0x10), the ring-buffer
 * slot the ARM7 last wrote while auto-sampling. Was misfiled under gx as GX_GetBankForOBJExtPltt. */

extern int data_02046390;

int TP_GetLatestIndexInAuto(void) {
    return *(unsigned short *)((int)&data_02046390 + 0x10);
}
