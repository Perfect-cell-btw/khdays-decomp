/* ov055 .data pointer tables, 0x020b7654-0x020b7668.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov055_BeginHitEffectIfEnabled(void);
extern void Ov055_PartAttackStep(void);

Ov_Fn data_ov055_020b7654[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov055_BeginHitEffectIfEnabled,

    Ov022_NullStep,

    Ov055_PartAttackStep,

};
