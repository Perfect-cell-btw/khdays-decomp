/* Rebuilds the parameter index and resets the party buffers. */

extern int Params_BuildIndex();
extern int PartyState_ResetBuffers();

void PartyState_Reset(void) {
    Params_BuildIndex();
    PartyState_ResetBuffers();
}
