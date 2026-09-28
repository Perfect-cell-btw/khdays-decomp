/* Resolve the argument, register it (slot 0) via ov106_020b8a24, notify 02033bb4 for id 0x2da
 * with flag 5 and report success. */
extern int ScriptVm_ReadOperandInt(int a);
extern void Ov106_SetGateFlag(int a, int b);
extern void ForwardToHandlerOrCurrentObject(int a, int b, int c);
int Ov106_CmdSetGateFlag(int param_1) {
    Ov106_SetGateFlag(0, ScriptVm_ReadOperandInt(param_1));
    ForwardToHandlerOrCurrentObject(0x2da, 0, 5);
    return 1;
}
