/* ov085 .data pointer tables, 0x020b91c0-0x020b91d4.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov085_PlayHitVoiceIfEnabled(void);

Ov_Fn data_ov085_020b91c0[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov085_PlayHitVoiceIfEnabled,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};
