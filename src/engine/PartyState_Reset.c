/* Rebuilds the parameter index and resets the party buffers. */

#include "game/engine.h"

void PartyState_Reset(void) {
    Params_BuildIndex();
    PartyState_ResetBuffers();
}
