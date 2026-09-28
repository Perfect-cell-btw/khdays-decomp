/* ov091 .data pointer tables, 0x020bc1a8-0x020bc1bc.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov091_StepProjectile(void);

Ov_Fn data_ov091_020bc1a8[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov091_StepProjectile,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};
