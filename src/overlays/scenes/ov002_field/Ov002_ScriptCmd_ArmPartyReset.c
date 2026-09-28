/* Script command: arms the party reset; returns 1. */

extern int Ov002_ArmPartyReset();

int Ov002_ScriptCmd_ArmPartyReset(int arg0) {
    Ov002_ArmPartyReset(arg0);
    return 1;
}
