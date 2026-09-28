/* Builds the mission member entries from the session's connected players (or the forced default)
 * and exchanges them with the peers before the entry sync. */

#include "nitro/types.h"

typedef void (*MissionCallback)(void);

typedef struct {
    u8 selectable : 1;
    u8 flag_1 : 1;
    u8 flag_2 : 1;
    u8 flag_3 : 1;
    u8 unused_4 : 4;
} MissionEntryFlags;

typedef struct {
    u8 index;
    MissionEntryFlags flags;
    s8 state;
    u8 reserved;
    u16 id;
} MissionEntry;

typedef struct {
    u32 locked : 1;
    u32 unused : 31;
    MissionEntry entries[4];
} MissionEntryBlock;

typedef struct {
    u8 pad_000[0x4a0];
    u32 update_mask;
    u32 input_ready;
    MissionEntryBlock live_entries;
    MissionEntryBlock sent_entries;
    MissionEntry local_entry;
    u8 pad_4e6[2];
    u32 exit_requested;
} MissionContext;

typedef struct {
    MissionContext *context;
    void *controller_instance;
} MissionGlobals;

extern MissionGlobals data_ov006_020565e4;
extern u16 GetGlobalU16At6(void);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern int Ov006_MenuSlotToEntry(int entry);
extern int Ov006_CanAdvancePastIntro(void);
extern int Session_IsReady(void);
extern u32 Session_GetLocalPlayerIndex(void);
extern int MsgQueue_SendGate(int type, u16 *payload, u16 size);
extern void StoreToGlobalPtr4Field28(int state);
extern void Ov006_UpdateAndGetIdleHandler(void);
extern void Ov006_UpdateMissionEntrySynchronization(void);

MissionCallback Ov006_SynchronizeMissionEntries(void) {
    int ready = 0;
    MissionCallback next = 0;

    if (data_ov006_020565e4.context->exit_requested != 0) {
        MissionEntry *entries = data_ov006_020565e4.context->live_entries.entries;
        u16 mask = GetGlobalU16At6();
        u8 i;

        MI_CpuFill8(&data_ov006_020565e4.context->live_entries, 0,
                    sizeof(MissionEntryBlock));
        for (i = 0; i < 4; i++) {
            entries[i].state = i;
            entries[i].flags.selectable = (mask & (1 << i)) != 0;
        }
        if (data_ov006_020565e4.context->exit_requested != 0) {
            entries[0].state = Ov006_MenuSlotToEntry(0);
        }
        data_ov006_020565e4.context->sent_entries =
            data_ov006_020565e4.context->live_entries;
        ready = 1;
    } else {
        if (Ov006_CanAdvancePastIntro() != 0) {
            return Ov006_UpdateAndGetIdleHandler;
        }

        if (Session_IsReady() != 0) {
            MissionEntry *entries = data_ov006_020565e4.context->live_entries.entries;
            u16 mask = GetGlobalU16At6();
            u8 i;

            MI_CpuFill8(&data_ov006_020565e4.context->live_entries, 0,
                        sizeof(MissionEntryBlock));
            for (i = 0; i < 4; i++) {
                entries[i].state = i;
                entries[i].flags.selectable = (mask & (1 << i)) != 0;
            }
            if (data_ov006_020565e4.context->exit_requested != 0) {
                entries[0].state = Ov006_MenuSlotToEntry(0);
            }
            data_ov006_020565e4.context->sent_entries =
                data_ov006_020565e4.context->live_entries;
            MsgQueue_SendGate(0xd,
                          (u16 *)&data_ov006_020565e4.context->live_entries,
                          sizeof(MissionEntryBlock));
            ready = 1;
        } else if (data_ov006_020565e4.context->update_mask == 1) {
            u16 localPlayer = Session_GetLocalPlayerIndex();
            MissionContext *context = data_ov006_020565e4.context;

            context->local_entry = context->live_entries.entries[localPlayer];
            context->local_entry.index = localPlayer;
            data_ov006_020565e4.context->update_mask = 0;
            ready = 1;
        } else {
            data_ov006_020565e4.context->update_mask = 0;
            data_ov006_020565e4.context->local_entry.flags.flag_1 = 0;
            data_ov006_020565e4.context->local_entry.index = Session_GetLocalPlayerIndex();
            data_ov006_020565e4.context->local_entry.state = -1;
            data_ov006_020565e4.context->local_entry.id = 0;
            MsgQueue_SendGate(0xd,
                          (u16 *)&data_ov006_020565e4.context->local_entry,
                          sizeof(MissionEntry));
        }
    }

    if (ready != 0) {
        StoreToGlobalPtr4Field28(2);
        next = Ov006_UpdateMissionEntrySynchronization;
    }
    return next;
}
