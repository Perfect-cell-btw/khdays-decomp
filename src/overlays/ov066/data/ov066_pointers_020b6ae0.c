/* ov066 .data pointer tables, 0x020b6ae0-0x020b6af4.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov066_PlayHitVoiceIfEnabled(void);

Ov_Fn data_ov066_020b6ae0[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov066_PlayHitVoiceIfEnabled,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};
