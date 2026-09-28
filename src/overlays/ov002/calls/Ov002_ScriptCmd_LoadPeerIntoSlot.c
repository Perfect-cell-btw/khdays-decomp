/* Script command: reads two int operands and loads the peer into the slot. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_LoadPeerIntoSlot();

int Ov002_ScriptCmd_LoadPeerIntoSlot(int arg0, int arg1) {
    int a = ScriptVm_ReadOperandInt(arg0, arg1);
    int b = ScriptVm_ReadOperandInt(arg0, arg1 + 8);
    Ov002_LoadPeerIntoSlot(a, b);
    return 1;
}
