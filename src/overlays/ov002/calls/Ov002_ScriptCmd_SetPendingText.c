extern int ByteCode_ResolveOperand();
extern int Ov106_SetPendingText();

int Ov002_ScriptCmd_SetPendingText(int arg0) {
    ByteCode_ResolveOperand(arg0);
    Ov106_SetPendingText();
    return 1;
}
