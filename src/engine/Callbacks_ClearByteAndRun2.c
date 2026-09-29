/* Clears the callback byte, then runs callback slot 2. */

#include "game/engine.h"

void Callbacks_ClearByteAndRun2(void) {
    PauseMenu_SetMode(0);
    Callbacks_Run(2);
}
