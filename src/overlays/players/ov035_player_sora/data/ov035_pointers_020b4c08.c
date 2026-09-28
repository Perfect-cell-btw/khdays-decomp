/* ov035 .data pointer tables, 0x020b4c08-0x020b4c1c.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov035_StepProjectile(void);

Ov_Fn data_ov035_020b4c08[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov035_StepProjectile,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};
