/* Ov026_Shop_ReleaseModel -- flush the ov026 scratch VRAM block, ov026 (tail-call to
 * ReleaseField74AndCleanup over *data_ov026_02091368 + 0xbff0). */

#include "game/engine.h"

extern char *data_ov026_02091368;
void Ov026_Shop_ReleaseModel(void) {
    ReleaseField74AndCleanup(data_ov026_02091368 + 0xbff0);
}
