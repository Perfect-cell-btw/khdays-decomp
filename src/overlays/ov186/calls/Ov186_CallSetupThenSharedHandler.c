/* Two-step teardown: Ov186_UnlinkHeldNode(param_1) then Ov107_AiState_OnDefeat(param_1). */
extern void Ov186_UnlinkHeldNode(int arg);
extern void Ov107_AiState_OnDefeat(int arg);
void Ov186_CallSetupThenSharedHandler(int param_1) {
    Ov186_UnlinkHeldNode(param_1);
    Ov107_AiState_OnDefeat(param_1);
}
