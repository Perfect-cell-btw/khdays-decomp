/* Script command: builds the scene id table; returns 1. */

extern int Ov107_Scene_BuildIdTable();

int Ov002_ScriptCmd_BuildSceneIdTable(int arg0) {
    Ov107_Scene_BuildIdTable(arg0);
    return 1;
}
