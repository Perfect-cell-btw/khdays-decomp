#include "game/ov008_camp_menu.h"
/* True only when the global exists, param_1's fields at +2/+8 are 0 and 7, and
 * bit 0 of the global flag byte at +0x42c is clear. */
#define MISSION_CONTEXT (data_ov008_02090f24.pContext)

struct b_02079c84 { unsigned char b0 : 1; };

int Ov008_MatchMissionStartPacket(int param_1) {
    int g = (int)data_ov008_02090f24.pContext;
    return g != 0
        && *(unsigned short *)(param_1 + 2) == 0
        && *(unsigned short *)(param_1 + 8) == 7
        && ((struct b_02079c84 *)(g + 0x42c))->b0 == 0;
}
