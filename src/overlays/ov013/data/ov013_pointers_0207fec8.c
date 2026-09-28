/* ov013 .data pointer tables, 0x0207fec8-0x0207fee0.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

typedef void (*Ov_Fn)(void);

extern void Ov013_MarshalFieldsAndInvoke(void);
extern void Ov013_CopyEquipTables(void);

Ov_Fn data_ov013_0207fec8[6] = {

    Ov013_MarshalFieldsAndInvoke,

    0,

    Ov013_CopyEquipTables,

    0,

    0,

    0,

};
