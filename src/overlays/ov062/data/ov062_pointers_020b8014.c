/* ov062 .data pointer tables, 0x020b8014-0x020b8028.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov062_UpdateSwingRequestEffect(void);

Ov_Fn data_ov062_020b8014[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov062_UpdateSwingRequestEffect,

    Ov022_NullStep,

    0,

};
