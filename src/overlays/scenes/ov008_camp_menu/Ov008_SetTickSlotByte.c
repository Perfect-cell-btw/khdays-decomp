#include "game/ov008_camp_menu.h"
/* Stores the mission slot byte (also into the screen flags for the host). */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
extern int func_01ff8128(void);

void Ov008_SetTickSlotByte(int value)
{
    MISSION_CONTEXT->selectionBlock[0x16] = value;

    if (func_01ff8128() == 0) {
        MISSION_CONTEXT->message.selection.peerStatus[func_01ff8128()] = value;
    }
}
