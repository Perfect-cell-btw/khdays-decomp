/* ov050 .data pointer tables, 0x020b74d4-0x020b74fc.
 *
 * 2 tables, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov050_HomingApproachTriggerStep(void);
extern void Ov050_HomingApproachStep(void);
extern void Ov050_advanceProjectileAndSteer(void);

Ov_Fn data_ov050_020b74d4[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov050_HomingApproachTriggerStep,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};

Ov_Fn data_ov050_020b74e8[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov050_HomingApproachStep,

    Ov022_NullStep,

    Ov050_advanceProjectileAndSteer,

};
