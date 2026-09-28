/* ov088 .data pointer tables, 0x020bc274-0x020bc29c.
 *
 * 2 tables, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov088_HomingApproachTriggerStep(void);
extern void Ov088_HomingApproachStep(void);
extern void Ov088_advanceProjectileAndSteer(void);

Ov_Fn data_ov088_020bc274[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov088_HomingApproachTriggerStep,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};

Ov_Fn data_ov088_020bc288[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov088_HomingApproachStep,

    Ov022_NullStep,

    Ov088_advanceProjectileAndSteer,

};
