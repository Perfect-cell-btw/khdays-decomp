/* ov025 .rodata pointer tables, 0x020b3cac-0x020b3cbc.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov025_FinishMenuModeSwitch(void);
extern void Ov025_UpdateReadyState(void);
extern void Ov025_TryAcquire14ThenClearField4(void);

const Ov_Fn data_ov025_020b3cac[4] = {

    0,

    Ov025_FinishMenuModeSwitch,

    Ov025_UpdateReadyState,

    Ov025_TryAcquire14ThenClearField4,

};
