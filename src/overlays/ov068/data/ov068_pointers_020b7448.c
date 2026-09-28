/* ov068 .data pointer tables, 0x020b7448-0x020b745c.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov068_TickThrowArcThenLand(void);

Ov_Fn data_ov068_020b7448[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov068_TickThrowArcThenLand,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};
