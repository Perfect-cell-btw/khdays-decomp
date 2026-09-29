/* Returns 2 when the actor has the double ability (0x58), otherwise 1. */

#include "game/engine.h"

int func_ov022_02095618(int arg0) {
    switch (Slot_EvalPackedParam(*(unsigned char *)(*(int *)(arg0 + 0x328) + 9), 0x58)) {
    case 1:
    case 2:
        return 2;
    }
    return 1;
}
