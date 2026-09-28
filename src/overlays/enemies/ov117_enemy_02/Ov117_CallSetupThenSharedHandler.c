/* Defeat handler: unlinks the held node, then runs the shared defeat handler. */

extern void Ov117_UnlinkHeldNode();
extern void Ov107_AiState_OnDefeat();

void Ov117_CallSetupThenSharedHandler(int this_) {
    Ov117_UnlinkHeldNode(this_);
    Ov107_AiState_OnDefeat(this_);
}
