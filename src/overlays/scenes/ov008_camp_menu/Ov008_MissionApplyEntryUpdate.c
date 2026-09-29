#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
#include "game/engine.h"
#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
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

        index = entry->playerIndex;
        if (!MISSION_CONTEXT->liveEntries.header.bits.locked &&
            entry->missionId !=
                MISSION_CONTEXT->liveEntries.entries[index].missionId &&
            entry->characterId >= 0) {
            MI_CpuCopy8(entry,
                        &MISSION_CONTEXT->liveEntries.entries[index],
                        sizeof(MissionEntry));
        }

        MISSION_CONTEXT->liveEntries.entries[index].flags.confirmed =
            entry->flags.confirmed;
        MISSION_CONTEXT->liveEntries.entries[index].flags.acknowledged =
            entry->flags.acknowledged;

        if (entry->characterId < 0) {
            MISSION_CONTEXT->liveEntries.entries[index].flags.request =
                entry->flags.request;
            MISSION_CONTEXT->liveEntries.entries[index].flags.acknowledged =
                0;
        }

        MISSION_CONTEXT->entryUpdateMask |= 1 << index;
        return;
    }

    if (size == sizeof(MISSION_CONTEXT->message.raw)) {
        MI_CpuCopy8(data, MISSION_CONTEXT->message.raw,
                    sizeof(MISSION_CONTEXT->message.raw));
        MISSION_CONTEXT->entryInputReady = 1;
    }

    if (size == sizeof(MissionEntryBlock)) {
        MI_CpuCopy8(data, &MISSION_CONTEXT->liveEntries,
                    sizeof(MissionEntryBlock));
        MISSION_CONTEXT->entryUpdateMask = 1;
    }
}
