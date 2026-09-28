/* Resolve the argument, register it (slot 0) via ov023_02089ccc, notify 02033bb4 for id 0x2da
 * with flag 5 and report success. */
extern int ScriptVm_ReadOperandInt(int a, int);
extern void Ov023_SetGateFlag(int a, int b);
extern void ForwardToHandlerOrCurrentObject(int a, int b, int c);
int Ov023_CmdSetGateFlag(int param_1, int arg1) {
    Ov023_SetGateFlag(0, ScriptVm_ReadOperandInt(param_1, arg1));
    ForwardToHandlerOrCurrentObject(0x2da, 0, 5);
    return 1;
}
