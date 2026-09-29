/* Sets or clears the global halfword value. */

extern void PartyState_SetInteraction(unsigned short arg0, int arg1);
void func_ov022_020ad5f4(int arg0, unsigned short arg1, int arg2) {
    if (arg2 != 0) PartyState_SetInteraction(arg1, 1);
    else PartyState_SetInteraction(arg1, 0);
}
