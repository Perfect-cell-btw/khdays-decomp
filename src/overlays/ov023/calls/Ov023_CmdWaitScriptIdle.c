/* Return whether Ov023_GetScriptState reports empty (returned zero). */
extern int Ov023_GetScriptState(int arg);
int Ov023_CmdWaitScriptIdle(int param_1) {
    return Ov023_GetScriptState(param_1) == 0;
}
