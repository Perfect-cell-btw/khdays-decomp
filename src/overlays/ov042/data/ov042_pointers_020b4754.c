/* ov042 .data pointer tables, 0x020b4754-0x020b4768.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);

Ov_Fn data_ov042_020b4754[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    0,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};
