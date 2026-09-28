/*
 * Game_ActionSetupNamedCall - action-command handler (opcode table data_020425ec). Reads three
 * operands from the command stream and stores a named call/task setup into the action state:
 *   - state+0x130 = ScriptVm_ReadOperandInt(state, cmd[0])   (first int parameter)
 *   - state+0x134 = ScriptVm_ReadOperandInt(state, cmd[4])   (second int parameter)
 *   - the name operand is cmd[8]: ScriptVm_ResolveOperand returns its slot; when the first word is
 *     zero the name buffer is cleared (state+0x138 = '\0'), otherwise the resolved string is copied
 *     with strncpy into the 0x40-byte buffer at state+0x138 and explicitly null-terminated at
 *     state+0x177 (0x138 + 0x3f).
 * Clears the pending-dispatch word (state+0x12c) and returns 3, which makes Game_RunActionScript
 * yield the interpreter for this frame.
 *
 * THUMB. The name-slot pointer is read signed (ldrsh); the resolved-operand pointer stays in a
 * callee-saved register across the two ReadOperandInt calls.
 */

#include "nitro/types.h"

extern short *ScriptVm_ResolveOperand(int st, u16 *cmd);   /* ScriptVm_ResolveOperand */
extern int    ScriptVm_ReadOperandInt(int st, u16 *cmd);   /* ScriptVm_ReadOperandInt */
extern char  *ByteCode_ResolveOperand(int st, short *op);  /* ByteCode_ResolveOperand */
extern char  *strncpy(char *dst, const char *src, int n);

int Game_ActionSetupNamedCall(int param_1, u16 *param_2)
{
    short *puVar1 = ScriptVm_ResolveOperand(param_1, param_2 + 8);
    *(int *)(param_1 + 0x130) = ScriptVm_ReadOperandInt(param_1, param_2);
    *(int *)(param_1 + 0x134) = ScriptVm_ReadOperandInt(param_1, param_2 + 4);
    if (*puVar1 == 0) {
        *(char *)(param_1 + 0x138) = 0;
    } else {
        char *s = (char *)ByteCode_ResolveOperand(param_1, puVar1);
        strncpy((char *)(param_1 + 0x138), s, 0x3f);
        *(char *)(param_1 + 0x177) = 0;
    }
    *(int *)(param_1 + 0x12c) = 0;
    return 3;
}
