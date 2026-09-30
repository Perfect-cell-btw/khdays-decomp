/* Resets save record `slot` for character `kind` at `level`: the level entry (LevelTable_ReadEntry) goes to
 * the record's stats (+8), the header takes slot / level / kind and the entry's +6 value, the 14
 * skill slots are cleared (Store2DArrayU8) and the character's signature skill (data_02042160, if
 * any) is set to the level rounded up to the next ten (at most 100).
 * Codegen: built with `opt_common_subs off` (push/pop scoped); with CSE on mwcc swaps the record
 * base and element pointer registers of the 8-byte header copy. */
#pragma thumb on

#include "nitro/types.h"

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    int fc;
} LevelEntry;

typedef struct {
    u8 slot;
    u8 kind;
    u8 level;
    u8 chara;
    u16 w4;
    u16 w6;
} SlotHeader;

typedef struct {
    SlotHeader header;
    LevelEntry stats;       /* 0x08 */
    u8 pad[0x104 - 0x18];
} SlotRecord;

typedef struct {
    int skill[22];
} SkillTable;

extern void LevelTable_ReadEntry(int kind, int level, LevelEntry *out);
extern void Store2DArrayU8(int slot, int skill, int level);
extern int func_02020400(int a, int b);   /* _s32_div_f */
extern LevelEntry data_0204c680[];
extern SlotRecord gPartyMembers[];
extern const SkillTable data_02042160;

#pragma push
#pragma opt_common_subs off
void PartyMember_Reset(int slot, int kind, int level)
{
    LevelEntry e;
    SlotHeader h;
    SkillTable table;
    int i;
    u8 lv;

    LevelTable_ReadEntry(kind, level, &e);
    *(LevelEntry *)((char *)data_0204c680 + slot * 0x104) = e;
    h = gPartyMembers[slot].header;
    h.level = level;
    h.chara = kind;
    h.slot = slot;
    h.w6 = e.f6;
    gPartyMembers[slot].header = h;
    for (i = 0; i < 0xe; i++) {
        Store2DArrayU8(slot, i, 0);
    }
    lv = (func_02020400(level + 1, 10) + 1) * 10;
    if (lv > 100) {
        lv = 100;
    }
    table = data_02042160;
    if (table.skill[kind] >= 0) {
        Store2DArrayU8(slot, table.skill[kind], lv);
    }
}
#pragma pop
