/* Script command: restores the suspended panel; returns 1. */

extern int Ov002_SuspendOrRestorePanel();

int Ov002_ScriptCmd_RestorePanel(void) {
    Ov002_SuspendOrRestorePanel(0);
    return 1;
}
