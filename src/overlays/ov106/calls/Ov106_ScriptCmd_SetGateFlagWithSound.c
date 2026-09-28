/* Resolve the argument, register it (slot 1) via ov106_020b8a24, notify 02033b24 for id 0x2da
 * and report success. */
extern int ScriptVm_ReadOperandInt(int a);
extern void Ov106_SetGateFlag(int a, int b);
extern void PlaySoundChecked(int a, int b);
int Ov106_ScriptCmd_SetGateFlagWithSound(int param_1) {
    Ov106_SetGateFlag(1, ScriptVm_ReadOperandInt(param_1));
    PlaySoundChecked(0x2da, 0);
    return 1;
}
