/* Clears the callback byte, then runs callback slot 2. */

#include "game/engine.h"

void Callbacks_ClearByteAndRun2(void) {
    Callbacks_SetByte(0);
    Callbacks_Run(2);
}
