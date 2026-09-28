#include "game/ov008_camp_menu.h"
/* Whether the link is local or ready. */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
extern int Ov008_Link_IsLocal(void);

int Ov008_Link_IsReady(void)
{
    if (MISSION_CONTEXT == 0) {
        return 1;
    }

    if (Ov008_Link_IsLocal() != 0) {
        return 1;
    }

    return MISSION_CONTEXT->transferB;
}
