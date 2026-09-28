extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern void Ov002_SetGroupOwner(unsigned int value, int arg);
extern unsigned char data_0204c240;
/* Script op: read a packed value and an argument; take the value's high half when global flag
 * bit 2 is set, else its low half, then dispatch. */
int Ov002_ScriptOpDispatchHalfWord(int vm, unsigned short *pc) {
    unsigned int v = ScriptVm_ReadOperandInt(vm, pc);
    int arg = ScriptVm_ReadOperandInt(vm, pc + 4);
    if ((data_0204c240 & 4) != 0) {
        v = (int)v >> 0x10;
    } else {
        v = v & 0xffff;
    }
    Ov002_SetGroupOwner(v, arg);
    return 1;
}
