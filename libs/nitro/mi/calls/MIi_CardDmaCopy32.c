

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

/* MIi_CardDmaCopy32 -- NitroSDK mi_dma_card.c. */
void MIi_CardDmaCopy32 (u32 dmaNo, const void * src, void * dest, u32 size)
{
    vu32 * dmaCntp;

    (void)size;

    MIi_CheckAnotherAutoDMA(dmaNo, MIi_DMA_TIMING_ANY);

    MIi_CheckDma0SourceAddress(dmaNo, (u32)src, size, MI_DMA_SRC_FIX);

    if (size == 0) {
        return;
    }

    MIi_Wait_BeforeDMA(dmaCntp, dmaNo);
    MIi_DmaSetParams(dmaNo, (u32)src, (u32)dest, (u32)(MI_CNT_CARDRECV32(4) | MI_DMA_CONTINUOUS_ON));
}
