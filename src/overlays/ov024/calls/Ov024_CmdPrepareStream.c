/* Resolve ScriptVm_ReadOperandInt(param_1) and pass it as the second arg to SoundMgr_PrepareStream
 * (mode 0); return 1. */
extern int ScriptVm_ReadOperandInt(int arg);
extern void SoundMgr_PrepareStream(int a, int b);
int Ov024_CmdPrepareStream(int param_1) {
    int r = ScriptVm_ReadOperandInt(param_1);
    SoundMgr_PrepareStream(0, r);
    return 1;
}
