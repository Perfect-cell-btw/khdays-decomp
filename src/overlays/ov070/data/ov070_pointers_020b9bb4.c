/* ov070 .data pointer tables, 0x020b9bb4-0x020b9bdc.
 *
 * 2 tables, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov070_HomingApproachTriggerStep(void);
extern void Ov070_HomingApproachStep(void);
extern void Ov070_advanceProjectileAndSteer(void);

Ov_Fn data_ov070_020b9bb4[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov070_HomingApproachTriggerStep,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};

Ov_Fn data_ov070_020b9bc8[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov070_HomingApproachStep,

    Ov022_NullStep,

    Ov070_advanceProjectileAndSteer,

};
