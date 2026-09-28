/* Script opcode: post a link message from three operands. Operand 0 is read as a
 * SIGNED halfword first -- a zero there means "no sender", encoded as -2, and
 * the operand is not resolved at all. Clears the pending slot at +0x12c and
 * reports 3. */
extern int ScriptVm_ReadOperandInt(void *self, void *arg);
extern void Ov002_UpdateHudRecord(int a, int b, int c);

int Ov002_ScriptPostLinkMessage(char *self, char *args) {
    int a;
    int b;
    int c;

    if (*(short *)args == 0) {
        a = -2;
    } else {
        a = ScriptVm_ReadOperandInt(self, args);
    }

    b = ScriptVm_ReadOperandInt(self, args + 8);
    c = ScriptVm_ReadOperandInt(self, args + 0x10);

    Ov002_UpdateHudRecord(a, b, c);
    *(int *)(self + 0x12c) = 0;
    return 3;
}
