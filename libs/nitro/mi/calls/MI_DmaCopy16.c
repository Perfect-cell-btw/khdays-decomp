

/* NitroSDK MI library: DMA transfers (mi_dma.c, mi_dma_card.c, mi_dma_gxcommand.c). */

#include "nitro/types.h"
#include "nitro/mi.h"
#include "nitro/os.h"

static inline void MIi_CallCallback(MIDmaCallback callback, void *arg)
{
    if (callback) {
        (callback)(arg);
    }
}

extern void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir);
extern void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType);
extern void MIi_DmaSetParams(u32 dmaNo, u32 src, u32 dest, u32 ctrl);
extern void func_01ff85d0(u32 dmaNo, u32 src, u32 dest, u32 ctrl);   /* MIi_DmaSetParams_wait (ITCM) */
#define MIi_DmaSetParams_wait func_01ff85d0
extern void MI_WaitDma(u32 dmaNo);
extern void OSi_EnterDmaCallback(u32 dmaNo, MIDmaCallback callback, void *arg);
extern u32 OS_ResetRequestIrqMask(u32 intr);
extern void OS_Terminate(void);

extern MIiGXDmaParams data_020446b0;   /* MIi_GXDmaParams */
#define MIi_GXDmaParams data_020446b0
extern void MIi_DMACallback(void *arg);
extern void MIi_DMAFastCallback(void *arg);

/* MI_DmaCopy16 -- NitroSDK mi_dma.c. */
void MI_DmaCopy16 (u32 dmaNo, const void * src, void * dest, u32 size)
{
    vu32 * dmaCntp;

    if (size == 0) {
        return;
    }

    MIi_CheckDma0SourceAddress(dmaNo, (u32)src, size, MI_DMA_SRC_INC);

    MIi_Wait_BeforeDMA(dmaCntp, dmaNo);
    MIi_DmaSetParams_wait(dmaNo, (u32)src, (u32)dest, MI_CNT_COPY16(size));
    MIi_Wait_AfterDMA(dmaCntp);
}
