/* ov000 .rodata pointer tables, 0x0205a86c-0x0205a884.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov000_TickFadeOutFromObjTimer(void);
extern void Ov000_TickFadeInFromObjTimer(void);
extern void Ov000_NavigateModeSelect(void);
extern void Ov000_SelectMenuSubMode(void);
extern void Ov000_ModeSelectStateNoOp(void);
extern void Ov000_ModeSelectStateNoOp_2(void);

const Ov_Fn data_ov000_0205a86c[6] = {

    Ov000_TickFadeOutFromObjTimer,

    Ov000_TickFadeInFromObjTimer,

    Ov000_NavigateModeSelect,

    Ov000_SelectMenuSubMode,

    Ov000_ModeSelectStateNoOp,

    Ov000_ModeSelectStateNoOp_2,

};
