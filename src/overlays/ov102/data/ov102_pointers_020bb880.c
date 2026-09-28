/* ov102 .data pointer tables, 0x020bb880-0x020bb894.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov022_StepStandingShot(void);
extern void Ov102_PlayHitVoiceIfEnabled(void);

Ov_Fn data_ov102_020bb880[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov102_PlayHitVoiceIfEnabled,

    Ov022_NullStep,

    Ov022_StepStandingShot,

};
