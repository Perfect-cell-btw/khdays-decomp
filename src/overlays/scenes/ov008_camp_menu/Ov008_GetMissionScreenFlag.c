#include "game/ov008_camp_menu.h"
/* Returns the mission screen's flag byte for the current value. */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
extern int func_01ff8128(void);

int Ov008_GetMissionScreenFlag(void)
{
    return (unsigned char)MISSION_CONTEXT->message.selection.peerStatus[func_01ff8128()];
}
