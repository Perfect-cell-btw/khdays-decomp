#include "nitro/types.h"

#include "game/ov006_mission_mode_select.h"
#include "game/engine.h"

/* Applies a mission entry update received over the link: copies the entry in when it changed
 * (unless the block is locked), updates its flags and marks it for redraw. */

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

void Ov006_MissionApplyEntryUpdate(const void *data, u32 size) {
    const MissionEntry *entry = data;

    Obj_GetWord28(data_ov006_020565e4.pController);
    if (data == 0) {
        return;
    }

    if (Session_IsReady() != 0) {
        u8 index;

        if (size != sizeof(MissionEntry)) {
            return;
        }

        index = entry->playerIndex;
        if (!data_ov006_020565e4.pContext->liveEntries.header.bits.locked &&
            entry->missionId !=
                data_ov006_020565e4.pContext->liveEntries.entries[index].missionId &&
            entry->characterId >= 0) {
            MI_CpuCopy8(entry,
                        &data_ov006_020565e4.pContext->liveEntries.entries[index],
                        sizeof(MissionEntry));
        }

        data_ov006_020565e4.pContext->liveEntries.entries[index].flags.confirmed =
            entry->flags.confirmed;
        data_ov006_020565e4.pContext->liveEntries.entries[index].flags.acknowledged =
            entry->flags.acknowledged;

        if (entry->characterId < 0) {
            data_ov006_020565e4.pContext->liveEntries.entries[index].flags.request =
                entry->flags.request;
            data_ov006_020565e4.pContext->liveEntries.entries[index].flags.acknowledged =
                0;
        }

        data_ov006_020565e4.pContext->entryUpdateMask |= 1 << index;
        return;
    }

    if (size == sizeof(data_ov006_020565e4.pContext->message.raw)) {
        MI_CpuCopy8(data, data_ov006_020565e4.pContext->message.raw,
                    sizeof(data_ov006_020565e4.pContext->message.raw));
        data_ov006_020565e4.pContext->entryInputReady = 1;
    }

    if (size == sizeof(MissionEntryBlock)) {
        MI_CpuCopy8(data, &data_ov006_020565e4.pContext->liveEntries,
                    sizeof(MissionEntryBlock));
        data_ov006_020565e4.pContext->entryUpdateMask = 1;
    }
}
