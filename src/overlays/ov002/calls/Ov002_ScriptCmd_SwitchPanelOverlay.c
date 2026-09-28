extern int ScriptVm_ReadOperandInt();
extern int Ov002_SwitchPanelOverlay();

int Ov002_ScriptCmd_SwitchPanelOverlay(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_SwitchPanelOverlay();
    return 1;
}
