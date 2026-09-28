/* ov008 .rodata pointer tables, 0x0208e87c-0x0208e8a4.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov008_UpdateCampaignMenuManager(void);
extern void Ov008_UpdateInputAndEnterMode3(void);
extern void Ov008_InitThenDispatchTwoHandlers(void);
extern void Ov008_WaitLoadAdvancePhase(void);
extern void Ov008_AllocWorkBufferInit(void);
extern void Ov008_UpdateInputAndEnableHalves(void);
extern void Ov008_UpdateInputAndEnterMode8(void);
extern void Ov008_FullScreenTeardown(void);
extern void Ov008_ScreenTeardown(void);

const Ov_Fn data_ov008_0208e87c[10] = {

    0,

    Ov008_UpdateCampaignMenuManager,

    Ov008_UpdateInputAndEnterMode3,

    Ov008_InitThenDispatchTwoHandlers,

    Ov008_WaitLoadAdvancePhase,

    Ov008_AllocWorkBufferInit,

    Ov008_UpdateInputAndEnableHalves,

    Ov008_UpdateInputAndEnterMode8,

    Ov008_ScreenTeardown,

    Ov008_FullScreenTeardown,

};
