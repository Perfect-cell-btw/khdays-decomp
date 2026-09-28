/* Two-step teardown: Ov185_UnlinkHeldNode(param_1) then Ov107_AiState_OnDefeat(param_1). */
extern void Ov185_UnlinkHeldNode(int arg);
extern void Ov107_AiState_OnDefeat(int arg);
void Ov185_CallSetupThenSharedHandler(int param_1) {
    Ov185_UnlinkHeldNode(param_1);
    Ov107_AiState_OnDefeat(param_1);
}
