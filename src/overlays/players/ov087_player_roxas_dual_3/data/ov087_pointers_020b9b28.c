/* ov087 .data pointer tables, 0x020b9b28-0x020b9b3c.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov087_TickThrowArcThenLand(void);

Ov_Fn data_ov087_020b9b28[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov087_TickThrowArcThenLand,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};
