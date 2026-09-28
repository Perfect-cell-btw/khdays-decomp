extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern int Ov002_PublishStateChange(int id, int kind, int value);
/* Script op: unpack id/kind from the opcode word, read the signed value operand, and apply it. */
int Ov002_ScriptOpApplyValueA(int vm, int op) {
    unsigned int packed = *(unsigned int *)(op + 4);
    int v = ScriptVm_ReadOperandInt(vm, (unsigned short *)(op + 8));
    if (Ov002_PublishStateChange(packed & 0xffff,
                            (unsigned char)(unsigned short)(packed >> 0x10),
                            (short)v) != 0) {
        return 1;
    }
    return 0;
}
