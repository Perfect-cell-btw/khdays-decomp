/* Script command: retires every list entry; returns 1. */

extern int Ov002_RetireAllListEntries();

int Ov002_ScriptCmd_RetireAllEntries(int arg0) {
    Ov002_RetireAllListEntries(arg0);
    return 1;
}
