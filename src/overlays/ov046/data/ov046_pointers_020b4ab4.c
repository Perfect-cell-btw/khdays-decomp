/* ov046 .data pointer tables, 0x020b4ab4-0x020b4ac8.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov046_InitRadialBurst(void);
extern void Ov046_StepHeldProjectile(void);

Ov_Fn data_ov046_020b4ab4[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov046_InitRadialBurst,

    Ov022_NullStep,

    Ov046_StepHeldProjectile,

};
