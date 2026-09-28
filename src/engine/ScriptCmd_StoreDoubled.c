/* Script command: stores twice the operand (plus a random bit when nonzero) in the current slot. */

extern int ScriptVm_ReadOperandInt(void *arg, int);
extern int VBlank_GetCount(void);
extern void Slot48_StoreAtCurrentIndex(void *arg, int adj);

int ScriptCmd_StoreDoubled(void *arg, int arg1) {
    int adj = ScriptVm_ReadOperandInt(arg, arg1) * 2;
    if (adj != 0) adj += VBlank_GetCount();
    Slot48_StoreAtCurrentIndex(arg, adj);
    return 0;
}
