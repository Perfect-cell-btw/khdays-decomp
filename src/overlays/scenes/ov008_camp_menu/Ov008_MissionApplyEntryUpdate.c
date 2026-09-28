#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
/* Applies a mission entry update received over the link: copies the entry in when it changed
 * (unless the block is locked), updates its flags and marks it for redraw. */

typedef struct {
    u8 unused_0 : 1;
    u8 flag_1 : 1;
    u8 flag_2 : 1;
    u8 flag_3 : 1;
    u8 unused_4 : 4;
} MissionEntryFlags;

typedef struct {
    u8 index;
    MissionEntryFlags flags;
    s8 state;
    u8 pad_03;
    u16 id;
} MissionEntry;

typedef struct {
    u32 locked : 1;
    u32 unused : 31;
    MissionEntry entries[4];
} MissionEntryBlock;

typedef struct {
    u8 pad_000[0x42c];
    u8 input_state[0x68];
    u8 pad_494[0xc];
    u32 update_mask;
    u32 input_ready;
    MissionEntryBlock entry_block;
} MissionContext;

#define MISSION_CONTEXT ((MissionContext *)data_ov008_02090f24.pContext)
extern void Obj_GetWord28(void *instance);
extern int Session_IsReady(void);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

void Ov008_MissionApplyEntryUpdate(const void *data, u32 size) {
    const MissionEntry *entry = data;

    Obj_GetWord28(data_ov008_02090f24.pController);
    if (data == 0) {
        return;
    }

    if (Session_IsReady() != 0) {
        u8 index;

        if (size != sizeof(MissionEntry)) {
            return;
        }

        index = entry->index;
        if (!MISSION_CONTEXT->entry_block.locked &&
            entry->id !=
                MISSION_CONTEXT->entry_block.entries[index].id &&
            entry->state >= 0) {
            MI_CpuCopy8(entry,
                        &MISSION_CONTEXT->entry_block.entries[index],
                        sizeof(MissionEntry));
        }

        MISSION_CONTEXT->entry_block.entries[index].flags.flag_2 =
            entry->flags.flag_2;
        MISSION_CONTEXT->entry_block.entries[index].flags.flag_3 =
            entry->flags.flag_3;

        if (entry->state < 0) {
            MISSION_CONTEXT->entry_block.entries[index].flags.flag_1 =
                entry->flags.flag_1;
            MISSION_CONTEXT->entry_block.entries[index].flags.flag_3 =
                0;
        }

        MISSION_CONTEXT->update_mask |= 1 << index;
        return;
    }

    if (size == sizeof(MISSION_CONTEXT->input_state)) {
        MI_CpuCopy8(data, MISSION_CONTEXT->input_state,
                    sizeof(MISSION_CONTEXT->input_state));
        MISSION_CONTEXT->input_ready = 1;
    }

    if (size == sizeof(MissionEntryBlock)) {
        MI_CpuCopy8(data, &MISSION_CONTEXT->entry_block,
                    sizeof(MissionEntryBlock));
        MISSION_CONTEXT->update_mask = 1;
    }
}
