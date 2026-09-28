#include "game/ov008_camp_menu.h"
/* Stores the mission slot byte (also into the screen flags for the host). */

#define MISSION_CONTEXT ((char *)data_ov008_02090f24.pContext)
extern int func_01ff8128(void);

void Ov008_SetTickSlotByte(int value)
{
    *(unsigned char *)(MISSION_CONTEXT + 0x42a) = value;

    if (func_01ff8128() == 0) {
        *(unsigned char *)(MISSION_CONTEXT + func_01ff8128() + 0x48e) = value;
    }
}
