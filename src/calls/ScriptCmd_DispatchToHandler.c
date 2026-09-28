/* Script command: resolves the operand and dispatches to the handler. */

extern int ScriptVm_ResolveOperand(void *p);
extern void ScriptVm_ReadOperandInt(void *p, int x);
extern void dispatchToHandlerAtOffset(void);

int ScriptCmd_DispatchToHandler(void *arg0) {
    int r = ScriptVm_ResolveOperand(arg0);
    ScriptVm_ReadOperandInt(arg0, r);
    dispatchToHandlerAtOffset();
    return 1;
}
