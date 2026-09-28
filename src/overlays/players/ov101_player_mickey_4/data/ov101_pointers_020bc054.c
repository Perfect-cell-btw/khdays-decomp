/* ov101 .data pointer tables, 0x020bc054-0x020bc068.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov101_InitRadialBurst(void);
extern void Ov101_StepHeldProjectile(void);

Ov_Fn data_ov101_020bc054[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov101_InitRadialBurst,

    Ov022_NullStep,

    Ov101_StepHeldProjectile,

};
