

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
extern void CTRDGi_LockByProcessor(int lockID, CTRDGLockByProc *info);
extern void CTRDGi_UnlockByProcessor(int lockID, CTRDGLockByProc *info);
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
/* ctrdg_proc.c: CTRDGi_Work is extern; isInitialized and headerBuf (ATTRIBUTE_ALIGN(32)) are its statics. */
extern CTRDGWork data_02046d4c;   /* CTRDGi_Work */
#define CTRDGi_Work data_02046d4c
/* isInitialized is the function's own static (see the body): only a function-scope static lets
 * the reg_OS_PAUSE read move above the store to it, as in the ROM; the module's delinked bss
 * keeps the symbol (tools/share_bss.py promotes the local `name$N` to the global). */
/* khdays: shared-bss */
extern CTRDGHeader data_02046d80 __attribute__((aligned(32)));   /* headerBuf */
#define headerBuf data_02046d80
extern BOOL CTRDG_IsExisting(void);   /* CTRDG_IsExisting */

/* CTRDGi_InitModuleInfo -- NitroSDK ctrdg_proc.c: CTRDGi_InitModuleInfo. */
void CTRDGi_InitModuleInfo (void)
{

	static BOOL data_02046d50;   /* isInitialized */
#define isInitialized data_02046d50
	CTRDGLockByProc lockInfo;
	OSIrqMask lastIE;
	BOOL lastIME;

	if (isInitialized) {
		return;
	}

	isInitialized = TRUE;

	if (!(reg_OS_PAUSE & REG_OS_PAUSE_CHK_MASK)) {
		return;
	}

	lastIE = OS_SetIrqMask(OS_IE_SPFIFO_RECV);
	lastIME = OS_EnableIrq();

	CTRDGi_LockByProcessor(CTRDGi_Work.lockID, &lockInfo);

	{
		MIProcessor proc = MI_GetMainMemoryPriority();
		CTRDGRomCycle rc;

		CTRDGi_ChangeLatestAccessCycle(&rc);

		MI_SetMainMemoryPriority(MI_PROCESSOR_ARM9);

		DC_InvalidateRange(&((u8 *)&headerBuf)[0x80], sizeof(headerBuf) - 0x80);
		MI_DmaCopy16(1, (void *)(HW_CTRDG_ROM + 0x80),
		             &((u8 *)&headerBuf)[0x80], sizeof(headerBuf) - 0x80);

		MI_SetMainMemoryPriority(proc);
		CTRDGi_RestoreAccessCycle(&rc);
	}

	CTRDGi_UnlockByProcessor(CTRDGi_Work.lockID, &lockInfo);

	if ((*(u8 *)HW_IS_CTRDG_EXIST) || !(*(u8 *)HW_SET_CTRDG_MODULE_INFO_ONCE)) {
		int i;
		CTRDGHeader *chb = &headerBuf;
		CTRDGModuleInfo *cip = CTRDGi_GetModuleInfoAddr();

		cip->moduleID.raw = chb->moduleID;
		for (i = 0; i < 3; i++) {
			cip->exLsiID[i] = chb->exLsiID[i];
		}
		cip->makerCode = chb->makerCode;
		cip->gameCode = chb->gameCode;

		*(u8 *)HW_IS_CTRDG_EXIST = (u8)((CTRDG_IsExisting())? 1 : 0);

		(*(u8 *)HW_SET_CTRDG_MODULE_INFO_ONCE) = TRUE;
	}

	MI_CpuCopy32((void *)CTRDG_SYSROM9_NINLOGO_ADR, &headerBuf.nintendoLogo, sizeof(headerBuf.nintendoLogo));
	DC_FlushAll();

	CTRDGi_SendtoPxi(CTRDG_PXI_COMMAND_INIT_MODULE_INFO | (((u32) & headerBuf - HW_MAIN_MEM) >> 5) << CTRDG_PXI_COMMAND_PARAM_SHIFT);

	while (CTRDGi_Work.subpInitialized != TRUE) {
		SVC_WaitByLoop(1);
	}

	(void)OS_RestoreIrq(lastIME);
	(void)OS_SetIrqMask(lastIE);

}
