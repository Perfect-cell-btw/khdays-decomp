extern int ScriptVm_ReadOperandInt(int a, void *b);
extern void ForwardToHandlerOrCurrentObject(int a, int b, int c);

int ScriptCmd_ForwardThreeToHandler(int param_1, unsigned short *param_2) {
    int a = ScriptVm_ReadOperandInt(param_1, param_2);
    int b = ScriptVm_ReadOperandInt(param_1, param_2 + 4);
    int c = ScriptVm_ReadOperandInt(param_1, param_2 + 8);
    ForwardToHandlerOrCurrentObject(a, b, c);
    return 1;
}
