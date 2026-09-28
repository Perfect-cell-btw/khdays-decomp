/* ov036 .data pointer tables, 0x020b4e54-0x020b4e68.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov036_BeginHitEffectIfEnabled(void);
extern void Ov036_PartAttackStep(void);

Ov_Fn data_ov036_020b4e54[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov036_BeginHitEffectIfEnabled,

    Ov022_NullStep,

    Ov036_PartAttackStep,

};
