/* Script command: reads two operands and requests the resource pair. */

#include "game/engine.h"

int ScriptCmd_RequestResPair(void *p, char *buf)
{
    int saved;
    saved = ScriptVm_ReadOperandInt(p, buf);
    ScriptVm_ReadOperandInt(p, buf + 8);
    Res_RequestIdPair(saved);
    return 1;
}
