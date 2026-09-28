#include "game/ov008_camp_menu.h"
/* Read the +0x30 word of element param of the ov008 global array. */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
int Ov008_GetPeerTileUploadPending(int index)
{
    return MISSION_CONTEXT->workStates[index];
}
