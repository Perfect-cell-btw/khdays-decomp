#include "game/ov008_camp_menu.h"
#include "game/engine.h"
/* Once per open (guard +0x48 within the 0x4a0 buffer): if the session is ready, run the ready
 * hook and blit the 0x1c-entry list at +8; otherwise blit the 6-entry fallback list at +0x40.
 * Either way clear the 4-byte header at +0. */
#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
extern void Ov008_MissionResolveDuplicateIds(void);

int Ov008_RefreshListView(void) {
    if (MISSION_CONTEXT->localMode == 0) {
        if (Session_IsReady()) {
            Ov008_MissionResolveDuplicateIds();
            MsgQueue_SendGate(0xd, &MISSION_CONTEXT->liveEntries, sizeof(MissionEntryBlock));
            MISSION_CONTEXT->entryUpdateMask = 0;
        } else {
            MISSION_CONTEXT->entryUpdateMask = 0;
            MsgQueue_SendGate(0xd, &MISSION_CONTEXT->localEntry, sizeof(MissionEntry));
        }
    }
    return 0;
}
