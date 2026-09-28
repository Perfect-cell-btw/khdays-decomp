/* Panel script command: reads an int operand and switches the panel overlay; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_SwitchPanelOverlay();

int Ov002_ScriptCmd_SwitchPanelOverlay(int arg0, void *cmd) {
        Ov002_SwitchPanelOverlay(ScriptVm_ReadOperandInt(arg0, cmd));
    return 1;
}
