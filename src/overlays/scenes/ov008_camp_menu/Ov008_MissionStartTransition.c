#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
/* Starts the mission link as parent: resolves the session id, picks the next group id, sets the
 * receive buffer, connects and installs the receiver and packet filter; marks the transition
 * requested. */

typedef struct {
    u8 pad_000[0x28];
    u32 transition_requested;
    u8 pad_02c[0x14];
    u8 option;
    u8 pad_041;
    u16 selection;
} MissionContext;

#define MISSION_CONTEXT (*(MissionContext * volatile *)&data_ov008_02090f24.pContext)
extern char data_ov008_02090f40[];

extern unsigned short Ov105_EnterState1AndResolveId(void);
extern unsigned short Ov105_WM_GetNextTgid(void);
extern void Ov105_SetBuffer(void *resource, int size);
extern int Ov105_WH_ParentConnect(int mode, int selection, int value, int count, int option);
extern void Ov105_WH_SetReceiver(void (*callback)(void));
extern void Ov105_SetPacketFilter(void (*callback)(void));
extern void Ov008_UpdateSlotCache(void);
extern void Ov008_MatchMissionStartPacket(void);

void Ov008_MissionStartTransition(void) {
    int value = Ov105_EnterState1AndResolveId();

    MISSION_CONTEXT->selection = (u16)Ov105_WM_GetNextTgid();
    Ov105_SetBuffer(data_ov008_02090f40, 0x18);

    if (Ov105_WH_ParentConnect(0, MISSION_CONTEXT->selection, value, 2,
                            MISSION_CONTEXT->option) == 0) {
        return;
    }

    Ov105_WH_SetReceiver(Ov008_UpdateSlotCache);
    Ov105_SetPacketFilter(Ov008_MatchMissionStartPacket);
    MISSION_CONTEXT->transition_requested = 1;
}
