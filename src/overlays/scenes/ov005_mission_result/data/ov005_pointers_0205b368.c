/* ov005 .rodata pointer tables, 0x0205b368-0x0205b38c.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov005_UpdateFadeIn(void);
extern void Ov005_WaitForMenuEntry(void);
extern void Ov005_UpdateRewardPresentation(void);
extern void Ov005_RefreshAndHandleCancel(void);
extern void Ov005_UpdateConfirmation(void);
extern void Ov005_WaitForExitTask(void);
extern void Ov005_LatchTickState7(void);
extern void Ov005_UpdateFadeOut(void);
extern void Ov005_MarkMenuExitRequested(void);

const Ov_Fn data_ov005_0205b368[9] = {

    Ov005_UpdateFadeIn,

    Ov005_WaitForMenuEntry,

    Ov005_UpdateRewardPresentation,

    Ov005_RefreshAndHandleCancel,

    Ov005_UpdateConfirmation,

    Ov005_WaitForExitTask,

    Ov005_LatchTickState7,

    Ov005_UpdateFadeOut,

    Ov005_MarkMenuExitRequested,

};
