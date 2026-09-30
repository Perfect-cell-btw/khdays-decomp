/* Two-step teardown: Ov187_UnlinkHeldNode(param_1) then Ov107_AiState_OnDefeat(param_1). */
extern void Ov187_UnlinkHeldNode(int arg);
extern void Ov107_AiState_OnDefeat(int arg);
void Ov187_CallSetupThenSharedHandler(int param_1) {
    Ov187_UnlinkHeldNode(param_1);
    Ov107_AiState_OnDefeat(param_1);
}
