/* Query ScriptVm_ReadOperandInt(param_1); report to Ov002_SetSessionActive whether it was
 * nonzero and its low byte. Always returns 1. */
extern int ScriptVm_ReadOperandInt(void *arg, int);
extern void Ov002_SetSessionActive(int present, int value);

int Ov002_ScriptCmd_SetSessionActive(void *param_1, int arg1) {
    int x = ScriptVm_ReadOperandInt(param_1, arg1);
    Ov002_SetSessionActive(x != 0, (unsigned char)x);
    return 1;
}
