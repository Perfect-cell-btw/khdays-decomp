/* Script command: reads an int operand and updates the slot lookup; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_UpdateSlotLookup();

int Ov002_ScriptCmd_UpdateSlotLookup(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_UpdateSlotLookup();
    return 1;
}
