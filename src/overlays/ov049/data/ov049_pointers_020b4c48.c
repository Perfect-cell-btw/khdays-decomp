/* ov049 .data pointer tables, 0x020b4c48-0x020b4c5c.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov049_TickThrowArcThenLand(void);

Ov_Fn data_ov049_020b4c48[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov049_TickThrowArcThenLand,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};
