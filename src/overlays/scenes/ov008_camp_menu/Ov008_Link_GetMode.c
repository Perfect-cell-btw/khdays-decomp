#include "game/ov008_camp_menu.h"
/* Mode byte of the link state (+0x100). */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
int Ov008_Link_GetMode(void)
{
    return MISSION_CONTEXT->rowCount;
}
