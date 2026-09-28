#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
#define SCENE_POLL_IDLE 4

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
extern int func_01ff8128(void);
extern u16 GetGlobalU16At4(void);                    /* recorded session id */
extern u16 func_01ff8138(void);    /* current session id */
extern int Game_PollSceneAlive(void);                    /* Game_PollSceneAlive */

int Ov008_IsMissionGroupStale(void)
{
    MissionContext *pCtx = MISSION_CONTEXT;
    u16 nRecorded;

    if (pCtx == 0 || pCtx->localMode != 0) {
        return 0;
    }
    if (func_01ff8128() == 0) {
        nRecorded = GetGlobalU16At4();
        if (nRecorded != func_01ff8138()) {
            MISSION_CONTEXT->liveEntries.header.bits.dirty = 1;
            return 1;
        }
    } else if (MISSION_CONTEXT->liveEntries.header.bits.dirty != 0) {
        return 1;
    }
    return Game_PollSceneAlive() != SCENE_POLL_IDLE;
}
