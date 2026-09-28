#include "game/ov008_camp_menu.h"
/* Once per open (guard +0x48 within the 0x4a0 buffer): if the session is ready, run the ready
 * hook and blit the 0x1c-entry list at +8; otherwise blit the 6-entry fallback list at +0x40.
 * Either way clear the 4-byte header at +0. */
struct Ov008ListContext {
    char _pad0[0x4a0];
    unsigned char pad04a0[0x50];
};
#define MISSION_CONTEXT ((struct Ov008ListContext *)data_ov008_02090f24.pContext)
extern int Session_IsReady(void);
extern void Ov008_MissionResolveDuplicateIds(void);
extern void MsgQueue_SendGate(int cmd, void *buf, int n);

int Ov008_RefreshListView(void) {
    if (*(int *)(MISSION_CONTEXT->pad04a0 + 0x48) == 0) {
        if (Session_IsReady()) {
            Ov008_MissionResolveDuplicateIds();
            MsgQueue_SendGate(0xd, MISSION_CONTEXT->pad04a0 + 8, 0x1c);
            *(int *)MISSION_CONTEXT->pad04a0 = 0;
        } else {
            *(int *)MISSION_CONTEXT->pad04a0 = 0;
            MsgQueue_SendGate(0xd, MISSION_CONTEXT->pad04a0 + 0x40, 6);
        }
    }
    return 0;
}
