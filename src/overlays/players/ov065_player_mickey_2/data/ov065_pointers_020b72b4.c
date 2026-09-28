/* ov065 .data pointer tables, 0x020b72b4-0x020b72c8.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov065_InitRadialBurst(void);
extern void Ov065_StepHeldProjectile(void);

Ov_Fn data_ov065_020b72b4[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov065_InitRadialBurst,

    Ov022_NullStep,

    Ov065_StepHeldProjectile,

};
