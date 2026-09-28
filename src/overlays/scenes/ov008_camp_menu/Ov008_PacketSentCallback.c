#include "game/ov008_camp_menu.h"
/* Send completion callback: clears the mission sync context's busy flag (+0x2c). */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
void Ov008_PacketSentCallback(void)
{
    MISSION_CONTEXT->sendBusy = 0;
}
