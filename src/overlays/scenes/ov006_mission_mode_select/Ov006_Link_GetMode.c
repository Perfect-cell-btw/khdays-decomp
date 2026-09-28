#include "game/ov006_mission_mode_select.h"
/* Mode byte of the link state (+0x100). */

/* Read the u8 field at (*(&data)) + 0x100. */
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
int Ov006_Link_GetMode(void) {
    return *(unsigned char *)((int)data_ov006_020565e4.pContext + 0x100);
}
