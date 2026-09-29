/* Whether the second argument equals the global halfword (IsArgEqualGlobalHalf4); the first is
 * ignored. Returns whether the second argument equals the global halfword. */

#include "game/engine.h"

int Ov022_ForwardArg1(int arg0, int arg1) { return IsArgEqualGlobalHalf4(arg1); }
