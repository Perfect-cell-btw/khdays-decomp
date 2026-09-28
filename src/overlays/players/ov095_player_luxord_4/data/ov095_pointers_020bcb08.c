/* ov095 .data pointer tables, 0x020bcb08-0x020bcb1c.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov095_SetMode4Delay3000(void);
extern void Ov095_TickThrowArcWithLimit(void);

Ov_Fn data_ov095_020bcb08[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov095_SetMode4Delay3000,

    Ov022_NullStep,

    Ov095_TickThrowArcWithLimit,

};
