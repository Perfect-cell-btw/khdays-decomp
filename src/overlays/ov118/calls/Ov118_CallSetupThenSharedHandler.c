extern void Ov118_UnlinkHeldNode();
extern void Ov107_AiState_OnDefeat();

void Ov118_CallSetupThenSharedHandler(int this_) {
    Ov118_UnlinkHeldNode(this_);
    Ov107_AiState_OnDefeat(this_);
}
