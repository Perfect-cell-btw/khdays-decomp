/* Script command: runs a condition from the table and stores the result in a game flag; returns 1.
 */

extern int ScriptVm_ReadOperandInt(void *a, void *b);
extern void Ov069_DispatchTableEntry(int a, int b, int c);

int Ov069_InitPairAndDispatch(void *arg1, char *arg2) {
    unsigned short idx = (unsigned short)*(int *)(arg2 + 4);
    int a = ScriptVm_ReadOperandInt(arg1, arg2 + 8);
    int b = ScriptVm_ReadOperandInt(arg1, arg2 + 0x10);
    Ov069_DispatchTableEntry(idx, a, b);
    return 1;
}
