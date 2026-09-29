/* Rebind the three collision items (+0x384 / +0x388 / +0x38c) to the resources of pose slot
 * `slot`: the kinds come from the data_ov244_020d3680 / 020d3658 / 020d36a8 tables (10 entries
 * each, copied to the stack), the entries live at +0x390 / +0x394 / +0x398. */

#include "game/enemy_common.h"

struct Tbl10 { int w[10]; };
extern void Ov244_RebindRenderEntry(int item, int tag, int flag, int *pEntry);
extern const struct Tbl10 data_ov244_020d3658;
extern const struct Tbl10 data_ov244_020d3680;
extern const struct Tbl10 data_ov244_020d36a8;

void Ov244_RebindCollisionSlot(int obj, int slot, int flag) {
    struct Tbl10 kindsA = data_ov244_020d3680;
    struct Tbl10 kindsB = data_ov244_020d3658;
    struct Tbl10 kindsC = data_ov244_020d36a8;

    Ov244_RebindRenderEntry(*(int *)(obj + 0x384), Ov107_PackTextureHandle((char *)obj, kindsA.w[slot]), flag, (int *)(obj + 0x390));
    Ov244_RebindRenderEntry(*(int *)(obj + 0x388), Ov107_PackTextureHandle((char *)obj, kindsB.w[slot]), flag, (int *)(obj + 0x394));
    Ov244_RebindRenderEntry(*(int *)(obj + 0x38c), Ov107_PackTextureHandle((char *)obj, kindsC.w[slot]), flag, (int *)(obj + 0x398));
}
