/* Resolve the argument, register it (slot 1) via ov023_02089ccc, notify 02033b24 for id 0x2da
 * and report success. */
extern int ScriptVm_ReadOperandInt(int a, int);
extern void Ov023_SetGateFlag(int a, int b);
extern void PlaySoundChecked(int a, int b);
int Ov023_ScriptCmd_SetGateFlagWithSound(int param_1, int arg1) {
    Ov023_SetGateFlag(1, ScriptVm_ReadOperandInt(param_1, arg1));
    PlaySoundChecked(0x2da, 0);
    return 1;
}
