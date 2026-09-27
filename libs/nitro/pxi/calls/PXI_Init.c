/* NitroSDK pxi (pxi_init.c): PXI_Init -- just PXI_InitFifo(), emitted as the interworking tail
 * call `ldr ip,[pc] ; bx ip`. It sits right before PXI_InitFifo and RTC_Init/PM_Init/TP_Init call
 * it exactly where the SDK calls PXI_Init. (Was misnamed WM_EndKeySharing_0x0200926c by shape.) */
extern void *PXI_InitFifo();

void *PXI_Init() {
    return PXI_InitFifo();
}
