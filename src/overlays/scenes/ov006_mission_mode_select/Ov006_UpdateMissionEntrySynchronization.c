/* Synchronises the chosen mission members with the peers: writes the chosen characters to the slot
 * table (resolving duplicates), sends and confirms the entries, then moves on. */

#include "nitro/types.h"
typedef void (*MissionCallback)(void);

typedef struct {
    u8 selectable : 1;
    u8 request : 1;
    u8 flag_2 : 1;
    u8 acknowledged : 1;
    u8 unused_4 : 4;
} MissionEntryFlags;

typedef struct {
    u8 playerIndex;
    MissionEntryFlags flags;
    s8 characterId;
    u8 reserved;
    u16 missionId;
} MissionEntry;

typedef struct {
    u32 locked : 1;
    u32 unused : 31;
    MissionEntry entries[4];
} MissionEntryBlock;

typedef struct {
    u32 active;
    int resourceSlot;
} MissionResourceSlot;

typedef struct {
    u8 pad_000[0x4a0];
    u32 entryUpdateMask;
    u32 entryInputReady;
    MissionEntryBlock liveEntries;
    MissionEntryBlock sentEntries;
    MissionEntry localEntry;
    u8 pad_4e6[2];
    u32 exitRequested;
    u16 messageHandle;
} MissionContext;

typedef struct {
    MissionContext *context;
    void *controllerInstance;
} MissionGlobals;

extern MissionGlobals data_ov006_020565e4;
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void CopyToSlotTable8(void *record, int index);
extern int Ov006_MenuEntryToSlot(int characterId);
extern u32 Session_GetLocalPlayerIndex(void);
extern int Ov006_CanAdvancePastIntro(void);
extern int Session_IsReady(void);
extern void Ov006_MissionResolveDuplicateIds(void);
extern int MsgQueue_SendGate(int type, u16 *payload, u16 size);
extern u16 GetGlobalU16At6(void);
extern u16 func_02031384(int type, void *payload, u16 size);
extern int MsgQueue_Contains(u32 handle);
extern void GameSession_SetSyncEnabled(int active);
extern void StoreToGlobalPtr4Field28(int state);
extern void Ov006_GetIdleHandlerGated(void);
extern void Ov006_UpdateAndGetIdleHandler(void);

MissionCallback Ov006_UpdateMissionEntrySynchronization(void) {
    MissionCallback result = 0;
    MissionContext *context = data_ov006_020565e4.context;

    if (context->exitRequested != 0) {
        if (context->liveEntries.locked) {
            MissionEntry *entries = context->liveEntries.entries;
            MissionResourceSlot slot;
            u8 outputIndex;
            u8 entryIndex;

            MI_CpuFill8(&slot, 0, sizeof(slot));
            for (entryIndex = 0; entryIndex < 4; entryIndex++) {
                CopyToSlotTable8(&slot, entryIndex);
            }

            outputIndex = 0;
            for (entryIndex = 0; entryIndex < 4; entryIndex++) {
                MI_CpuFill8(&slot, 0, sizeof(slot));
                if (entries[entryIndex].flags.selectable) {
                    slot.active = 1;
                    slot.resourceSlot = Ov006_MenuEntryToSlot(
                        entries[entryIndex].characterId);
                    CopyToSlotTable8(&slot, outputIndex);
                    outputIndex = (outputIndex + 1) & 0xff;
                }
            }
            result = Ov006_GetIdleHandlerGated;
        }
    } else {
        Session_GetLocalPlayerIndex();
        if (Ov006_CanAdvancePastIntro() != 0) {
            return Ov006_UpdateAndGetIdleHandler;
        }

        if (Session_IsReady() != 0) {
            if (data_ov006_020565e4.context->entryUpdateMask != 0) {
                u16 sessionMask;
                u8 entryIndex;

                data_ov006_020565e4.context->entryUpdateMask = 0;
                Ov006_MissionResolveDuplicateIds();
                MsgQueue_SendGate(0xd,
                    (u16 *)&data_ov006_020565e4.context->liveEntries,
                    sizeof(MissionEntryBlock));

                if (data_ov006_020565e4.context->liveEntries.locked) {
                    MissionResourceSlot slot;
                    MissionEntry *entries;
                    int peerIndex;
                    u8 *peerFlags;
                    u8 *peerFlagsBase;
                    u8 outputIndex;

                    sessionMask = GetGlobalU16At6();
                    context = data_ov006_020565e4.context;
                    peerIndex = 1;
                    peerFlagsBase = (u8 *)&context->liveEntries.entries[0].flags;
                    peerFlags = peerFlagsBase + sizeof(MissionEntry);
                    do {
                        if ((sessionMask & (1 << peerIndex)) != 0 &&
                            !((MissionEntryFlags *)peerFlags)->acknowledged) {
                            return 0;
                        }
                        peerIndex++;
                        peerFlags += sizeof(MissionEntry);
                    } while (peerIndex < 4);

                    entries = context->liveEntries.entries;
                    MI_CpuFill8(&slot, 0, sizeof(slot));
                    for (entryIndex = 0; entryIndex < 4; entryIndex++) {
                        CopyToSlotTable8(&slot, entryIndex);
                    }

                    outputIndex = 0;
                    for (entryIndex = 0; entryIndex < 4; entryIndex++) {
                        MI_CpuFill8(&slot, 0, sizeof(slot));
                        if (entries[entryIndex].flags.selectable) {
                            slot.active = 1;
                            slot.resourceSlot = Ov006_MenuEntryToSlot(
                                entries[entryIndex].characterId);
                            CopyToSlotTable8(&slot, outputIndex);
                            outputIndex = (outputIndex + 1) & 0xff;
                        }
                    }
                    result = Ov006_GetIdleHandlerGated;
                }
            }
        } else {
            context = data_ov006_020565e4.context;
            if (context->liveEntries.locked) {
                if (context->messageHandle == 0xffff) {
                    u16 messageHandle;

                    context->localEntry.flags.acknowledged = 1;
                    messageHandle = func_02031384(
                        0xd, &data_ov006_020565e4.context->localEntry,
                        sizeof(MissionEntry));
                    data_ov006_020565e4.context->messageHandle = messageHandle;
                    return 0;
                }

                if (MsgQueue_Contains(context->messageHandle) == 0) {
                    MissionResourceSlot slot;
                    MissionEntry *entries;
                    u8 outputIndex;
                    u8 entryIndex;

                    data_ov006_020565e4.context->messageHandle = 0xffff;
                    context = data_ov006_020565e4.context;
                    entries = context->liveEntries.entries;
                    MI_CpuFill8(&slot, 0, sizeof(slot));
                    for (entryIndex = 0; entryIndex < 4; entryIndex++) {
                        CopyToSlotTable8(&slot, entryIndex);
                    }

                    outputIndex = 0;
                    for (entryIndex = 0; entryIndex < 4; entryIndex++) {
                        MI_CpuFill8(&slot, 0, sizeof(slot));
                        if (entries[entryIndex].flags.selectable) {
                            slot.active = 1;
                            slot.resourceSlot = Ov006_MenuEntryToSlot(
                                entries[entryIndex].characterId);
                            CopyToSlotTable8(&slot, outputIndex);
                            outputIndex = (outputIndex + 1) & 0xff;
                        }
                    }
                    result = Ov006_GetIdleHandlerGated;
                }
            } else {
                MsgQueue_SendGate(0xd, (u16 *)&context->localEntry,
                              sizeof(MissionEntry));
            }
        }
    }

    if (result == Ov006_GetIdleHandlerGated) {
        GameSession_SetSyncEnabled(1);
        StoreToGlobalPtr4Field28(3);
    }
    return result;
}
