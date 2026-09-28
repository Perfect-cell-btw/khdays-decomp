/* Script command: resolves a text operand and sets it as the pending text; returns 1. */

extern int ByteCode_ResolveOperand(int script, unsigned short *operand);
extern void Ov106_SetPendingText(const char *fmt);

int Ov002_ScriptCmd_SetPendingText(int arg0, unsigned short *arg1) {
    Ov106_SetPendingText((const char *)ByteCode_ResolveOperand(arg0, arg1));
    return 1;
}
