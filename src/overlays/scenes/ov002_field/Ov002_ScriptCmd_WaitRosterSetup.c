/* Script command: done once the roster setup has advanced. */

extern int Ov002_AdvanceRosterSetup();

int Ov002_ScriptCmd_WaitRosterSetup(void) {
    return Ov002_AdvanceRosterSetup(-1) != 0;
}
