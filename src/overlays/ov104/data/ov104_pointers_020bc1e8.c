/* ov104 .data pointer tables, 0x020bc1e8-0x020bc1fc.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov104_TickThrowArcThenLand(void);

Ov_Fn data_ov104_020bc1e8[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov104_TickThrowArcThenLand,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};
