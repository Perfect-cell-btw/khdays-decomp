/* Script command: stores twice the operand (plus a random bit when nonzero) in the current slot. */

extern int ScriptVm_ReadOperandInt(void *arg);
extern int func_01ff80a8(void);
extern void Slot48_StoreAtCurrentIndex(void *arg, int adj);

int ScriptCmd_StoreDoubled(void *arg) {
    int adj = ScriptVm_ReadOperandInt(arg) * 2;
    if (adj != 0) adj += func_01ff80a8();
    Slot48_StoreAtCurrentIndex(arg, adj);
    return 0;
}
