/* Frees a non-null stack allocation. */

#include "game/engine.h"

int StackAlloc_FreeIfSetB(int a) {
    if (a) StackAlloc_FreeIfSet(a);
}
