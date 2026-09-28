/* Script command: reads two operands and requests the resource pair. */

extern int ScriptVm_ReadOperandInt(void *a, void *b);
extern int Res_RequestIdPair(int x);

int ScriptCmd_RequestResPair(void *p, char *buf)
{
    int saved;
    saved = ScriptVm_ReadOperandInt(p, buf);
    ScriptVm_ReadOperandInt(p, buf + 8);
    Res_RequestIdPair(saved);
    return 1;
}
