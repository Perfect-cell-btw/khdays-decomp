/* ov011 .rodata pointer tables, 0x0205dc90-0x0205dca0.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov011_InvokeWithMainBldcnt(void);
extern void Ov011_InvokeWithSubBldcnt(void);
extern void Ov011_ClearBlendA(void);
extern void Ov011_ClearBlendB(void);

const Ov_Fn data_ov011_0205dc90[4] = {

    Ov011_InvokeWithMainBldcnt,

    Ov011_ClearBlendA,

    Ov011_InvokeWithSubBldcnt,

    Ov011_ClearBlendB,

};
