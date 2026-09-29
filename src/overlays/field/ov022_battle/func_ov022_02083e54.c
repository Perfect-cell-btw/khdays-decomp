/* Returns 0 when the screen is at full brightness and the context state is negative, otherwise 1.
 */

#include "game/engine.h"

extern int *data_ov022_020b2e60;
int func_ov022_02083e54(void) {
    if (data_ov022_020b2e60 != 0 && func_0201e428() == 0 && *(char *)((char *)data_ov022_020b2e60 + 0x3e) < 0) {
        return 0;
    }
    return 1;
}
