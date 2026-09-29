/* Script command: scales a list entry's tag by the operands; returns 1. */

#include "game/engine.h"

extern void Ov002_List_ScaleEntryTag(int a, int b);
extern void Ov017_RegisterHookNoOp(void);

int Ov017_RegisterPairAndDispatch(void *arg1, char *arg2) {
    int a = ScriptVm_ReadOperandInt(arg1, arg2);
    int b = ScriptVm_ReadOperandInt(arg1, arg2 + 8);
    Ov002_List_ScaleEntryTag((unsigned char)a, (unsigned short)b);
    Ov017_RegisterHookNoOp();
    return 1;
}
