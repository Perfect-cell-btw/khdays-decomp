#include "nitro/types.h"

#include "game/ov006_mission_mode_select.h"

/* Finishes the mission input transition: releases the service, and either restarts it in exit mode
 * or pushes the display config (with the key block when needed), restarts it and installs the
 * entry-update handler; marks it active. */

typedef struct {
    u32 mode;
    u32 keycode;
    u32 rawKeys;
    u16 packedKeys;
} MissionDisplayConfig;

#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

extern void Ov105_WH_SetReceiver(void *callback);
extern void ReleaseServiceInstance(void);
extern void func_02031600(void *config);
extern void EnsureServiceInstance(void);
extern int func_01ff8128(void);
extern void Ov006_MissionPushDisplayConfig(void);
extern void StoreGlobalPtrArray4At0c(int slot, void *callback);
extern void Ov006_MissionApplyEntryUpdate(void);

void Ov006_MissionUpdateInputTransition(void) {
    MissionDisplayConfig exit_config;
    MissionDisplayConfig key_config;
    MissionKeyBlock *key_block;

    MISSION_CONTEXT->transitionRequested = 0;
    if (MISSION_CONTEXT->localMode == 0) {
        Ov105_WH_SetReceiver(0);
    }
    ReleaseServiceInstance();

    if (MISSION_CONTEXT->localMode != 0) {
        exit_config.mode = 1;
        exit_config.keycode = 1;
        func_02031600(&exit_config);
        EnsureServiceInstance();
    } else {
        if (func_01ff8128() == 0) {
            Ov006_MissionPushDisplayConfig();
        } else {
            key_block = &MISSION_CONTEXT->message.keys;
            Ov006_MissionPushDisplayConfig();
            key_config.mode = 3;
            key_config.rawKeys = key_block->rawKeys;
            key_config.packedKeys = key_block->packedKeys;
            func_02031600(&key_config);
        }
        EnsureServiceInstance();
        StoreGlobalPtrArray4At0c(0xd, Ov006_MissionApplyEntryUpdate);
    }

    MISSION_CONTEXT->entryUpdateMask = 1;
}
