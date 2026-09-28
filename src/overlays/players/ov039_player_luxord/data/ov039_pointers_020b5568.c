/* ov039 .data pointer tables, 0x020b5568-0x020b557c.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov039_SetMode4Delay3000(void);
extern void Ov039_TickThrowArcWithLimit(void);

Ov_Fn data_ov039_020b5568[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov039_SetMode4Delay3000,

    Ov022_NullStep,

    Ov039_TickThrowArcWithLimit,

};
