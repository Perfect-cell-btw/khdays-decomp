/* Script command: creates the field context; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_CreateFieldContext();

int Ov002_ScriptCmd_CreateFieldContext(int arg0, void *cmd) {
        Ov002_CreateFieldContext(ScriptVm_ReadOperandInt(arg0, cmd));
    return 1;
}
