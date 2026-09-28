/* Script command: builds the key entry table; returns 1. */

extern int Ov002_BuildKeyEntryTable();

int Ov002_ScriptCmd_BuildKeyEntryTable(int arg0) {
    Ov002_BuildKeyEntryTable(arg0);
    return 1;
}
