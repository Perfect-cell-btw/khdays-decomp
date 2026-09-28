/* Script command: resets the tracks; returns 1. */

extern int Ov002_ResetTracks();

int Ov002_ScriptCmd_ResetTracks(int arg0) {
    Ov002_ResetTracks(arg0);
    return 1;
}
