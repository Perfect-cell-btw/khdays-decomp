/* Script opcode: drive Ov002_SetKeyNodeVisible with three operands, the first
 * narrowed differently depending on the boot mode -- bit 2 of data_0204c240
 * takes the SIGNED high halfword, otherwise the unsigned low one. Reports 1. */
extern int ScriptVm_ReadOperandInt(void *self, void *arg);
extern void Ov002_SetKeyNodeVisible(int a, int b, int c);

extern unsigned char data_0204c240;

int Ov002_ScriptDriveWithModeHalfword(void *self, char *args) {
    int a = ScriptVm_ReadOperandInt(self, args);
    int b = ScriptVm_ReadOperandInt(self, args + 8);
    int c = ScriptVm_ReadOperandInt(self, args + 0x10);
    int value;

    if (data_0204c240 & 4) {
        value = a >> 0x10;
    } else {
        value = (unsigned short)a;
    }

    Ov002_SetKeyNodeVisible(value, b, c);
    return 1;
}
