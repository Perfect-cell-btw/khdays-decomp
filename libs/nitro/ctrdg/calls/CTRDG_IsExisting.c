

/* NitroSDK CTRDG library (ctrdg_common.h / ctrdg_work.h): the AGB cartridge slot. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nitro/ctrdg.h"

typedef int PXIFifoTag;
#define reg_MI_EXMEMCNT (*(vu16 *)REG_EXMEMCNT_ADDR)
#define reg_OS_IME      (*(vu16 *)REG_IME_ADDR)
#define reg_OS_PAUSE    (*(vu16 *)REG_PAUSE_ADDR)
#define PXI_FIFO_TAG_CTRDG 13
#define PXI_FIFO_SUCCESS 0

                    /* 0xc0 */

                /* 0x0c */

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern OSIrqMask OS_SetIrqMask(OSIrqMask intr);
extern void CTRDGi_LockByProcessor(u16 lockID, CTRDGLockByProc *info);
extern void CTRDGi_UnlockByProcessor(u16 lockID, CTRDGLockByProc *info);
extern void CTRDGi_ChangeLatestAccessCycle(CTRDGRomCycle *r);
extern void CTRDGi_RestoreAccessCycle(CTRDGRomCycle *r);
extern void CTRDGi_SendtoPxi(u32 data);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_FlushAll(void);
extern void MI_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size);
extern void MIi_CpuCopy32(const void *src, void *dest, u32 size);
extern int PXI_SendWordByFifo(int tag, u32 data, BOOL err);   /* PXI_SendWordByFifo */
extern void WaitByLoop(s32 count);   /* SVC_WaitByLoop */
#define SVC_WaitByLoop WaitByLoop

static inline void MI_SetCartridgeRomCycle1st(MICartridgeRomCycle1st c1)
{
    reg_MI_EXMEMCNT =
        (u16)((reg_MI_EXMEMCNT & ~REG_MI_EXMEMCNT_ROM1st_MASK) |
              (c1 << REG_MI_EXMEMCNT_ROM1st_SHIFT));
}

static inline MICartridgeRomCycle1st MI_GetCartridgeRomCycle1st(void)
{
    return (MICartridgeRomCycle1st)((reg_MI_EXMEMCNT & REG_MI_EXMEMCNT_ROM1st_MASK) >>
                                    REG_MI_EXMEMCNT_ROM1st_SHIFT);
}

static inline void MI_SetCartridgeRomCycle2nd(MICartridgeRomCycle2nd c2)
{
    reg_MI_EXMEMCNT =
        (u16)((reg_MI_EXMEMCNT & ~REG_MI_EXMEMCNT_ROM2nd_MASK) |
              (c2 << REG_MI_EXMEMCNT_ROM2nd_SHIFT));
}

static inline MICartridgeRomCycle2nd MI_GetCartridgeRomCycle2nd(void)
{
    return (MICartridgeRomCycle2nd)((reg_MI_EXMEMCNT & REG_MI_EXMEMCNT_ROM2nd_MASK) >>
                                    REG_MI_EXMEMCNT_ROM2nd_SHIFT);
}

static inline void MI_SetMainMemoryPriority(MIProcessor proc)
{
    reg_MI_EXMEMCNT =
        (u16)((reg_MI_EXMEMCNT & ~REG_MI_EXMEMCNT_EP_MASK) | (proc << REG_MI_EXMEMCNT_EP_SHIFT));
}

static inline MIProcessor MI_GetMainMemoryPriority(void)
{
    return (MIProcessor)((reg_MI_EXMEMCNT & REG_MI_EXMEMCNT_EP_MASK) >> REG_MI_EXMEMCNT_EP_SHIFT);
}

static inline BOOL OS_EnableIrq(void)
{
    u16 prep = reg_OS_IME;
    reg_OS_IME = OS_IME_ENABLE;
    return (BOOL)prep;
}

static inline BOOL OS_RestoreIrq(BOOL enable)
{
    u16 prep = reg_OS_IME;
    reg_OS_IME = (u16)enable;
    return (BOOL)prep;
}
/* ctrdg.c defines CTRDGi_EnableFlag and CTRDGi_Work back to back in its .bss, and the ROM
 * addresses CTRDGi_Work.lockID off that block's base (+6): the two statics as one overlay. */
extern struct { BOOL enableFlag; CTRDGWork work; } data_02046d48;   /* CTRDGi_EnableFlag + CTRDGi_Work */
#define CTRDGi_Work data_02046d48.work

/* CTRDG_IsExisting -- NitroSDK ctrdg.c: CTRDG_IsExisting. */
BOOL CTRDG_IsExisting (void)
{
	BOOL retval = TRUE;
	CTRDGLockByProc lockInfo;

	CTRDGHeader *chp = CTRDGi_GetHeaderAddr();
	CTRDGModuleInfo *cip = CTRDGi_GetModuleInfoAddr();

	if (cip->moduleID.raw == 0xffff) {
		return FALSE;
	}

	if (cip->detectPullOut == TRUE) {
		return FALSE;
	}
	CTRDGi_LockByProcessor(CTRDGi_Work.lockID, &lockInfo);

	{
		CTRDGRomCycle rc;
		u8 isRomCode;

		CTRDGi_ChangeLatestAccessCycle(&rc);
		isRomCode = chp->isRomCode;

		if ((isRomCode == CTRDG_IS_ROM_CODE && cip->moduleID.raw != chp->moduleID)
		    || (isRomCode != CTRDG_IS_ROM_CODE && cip->moduleID.raw != *CTRDGi_GetModuleIDImageAddr())
		    || ((cip->gameCode != chp->gameCode) && cip->isAgbCartridge)) {
			cip->detectPullOut = TRUE;
			retval = FALSE;
		}

		CTRDGi_RestoreAccessCycle(&rc);
	}

	CTRDGi_UnlockByProcessor(CTRDGi_Work.lockID, &lockInfo);
	return retval;
}
