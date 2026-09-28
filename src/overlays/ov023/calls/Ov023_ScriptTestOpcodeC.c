extern short LoadGlobalU16At0(void);
extern int Ov023_GetScriptState(void);
/* Script predicate: true (0) only if the current opcode is 0xc and func_02084018 is non-zero. */
int Ov023_ScriptTestOpcodeC(void) {
    if (LoadGlobalU16At0() != 0xc) {
        return 1;
    }
    if (Ov023_GetScriptState() == 0) {
        return 1;
    }
    return 0;
}
