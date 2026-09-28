/* Script opcode: resolve four operands and drive Ov002_StampEntry with them,
 * the third narrowed to an unsigned halfword and the fourth to a signed byte,
 * with -1 as the fifth (stack) argument. Reports 1. */
extern int ScriptVm_ReadOperandInt(void *self, void *arg);
extern void Ov002_StampEntry(int a, int b, int c, int d, int e);

int Ov002_ScriptDriveFourOperands(void *self, char *args) {
    int a = ScriptVm_ReadOperandInt(self, args);
    int b = ScriptVm_ReadOperandInt(self, args + 8);
    int c = ScriptVm_ReadOperandInt(self, args + 0x10);
    int d = ScriptVm_ReadOperandInt(self, args + 0x18);

    Ov002_StampEntry(a, b, (unsigned short)c, (signed char)d, -1);
    return 1;
}
