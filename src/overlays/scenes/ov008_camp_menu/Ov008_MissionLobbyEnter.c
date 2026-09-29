#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
#include "game/engine.h"
#define GATE_LOBBY  0xd
#define TARGET_ANY  -1                                  /* signed byte: the ROM materialises it with mvn */

typedef void *(*Ov008StateFn)(void);

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
extern void *Ov008_MissionLobbyJoin(void);                           /* next lobby state */

void *Ov008_MissionLobbyEnter(void)
{
    MISSION_CONTEXT->transferB = 0;
    MISSION_CONTEXT->transferA = 0;
    MISSION_CONTEXT->liveEntries.header.bits.locked = 0;
    MISSION_CONTEXT->localEntry.flags.request = 0;
    if (Session_IsReady() == 0) {
        MISSION_CONTEXT->entryUpdateMask = 0;
        MISSION_CONTEXT->localEntry.playerIndex = Session_GetLocalPlayerIndex();
        MISSION_CONTEXT->localEntry.flags.request = 0;
        MISSION_CONTEXT->localEntry.characterId = TARGET_ANY;
        MISSION_CONTEXT->localEntry.missionId = 0;
        MsgQueue_SendGate(GATE_LOBBY, &MISSION_CONTEXT->localEntry, sizeof(MissionEntry));
    }
    return (void *)Ov008_MissionLobbyJoin;
}
