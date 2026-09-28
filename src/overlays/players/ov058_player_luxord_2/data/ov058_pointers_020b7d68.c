/* ov058 .data pointer tables, 0x020b7d68-0x020b7d7c.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov022_AdvanceTimerAndLatchDone(void);
extern void Ov022_NullStep(void);
extern void Ov058_SetMode4Delay3000(void);
extern void Ov058_TickThrowArcWithLimit(void);

Ov_Fn data_ov058_020b7d68[5] = {

    0,

    Ov022_AdvanceTimerAndLatchDone,

    Ov058_SetMode4Delay3000,

    Ov022_NullStep,

    Ov058_TickThrowArcWithLimit,

};
