/* ov002 .data pointer tables, 0x0207eed8-0x0207eee8.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov002_ClosePageIfAllowed(void);
extern void func_ov002_020673d4(void);
extern void Ov002_HandleHudPageKeys(void);

Ov_Fn data_ov002_0207eed8[4] = {

    Ov002_HandleHudPageKeys,

    Ov002_ClosePageIfAllowed,

    func_ov002_020673d4,

    0,

};
