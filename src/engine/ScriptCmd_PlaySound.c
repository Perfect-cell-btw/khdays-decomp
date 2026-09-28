/* Script command: reads two int operands and plays that sound (PlaySoundChecked); returns 1. */

extern int ScriptVm_ReadOperandInt(int a, void *b);
extern void PlaySoundChecked(int a, int b);

int ScriptCmd_PlaySound(int param_1, unsigned short *param_2) {
    int a = ScriptVm_ReadOperandInt(param_1, param_2);
    int b = ScriptVm_ReadOperandInt(param_1, param_2 + 4);
    PlaySoundChecked(a, b);
    return 1;
}
