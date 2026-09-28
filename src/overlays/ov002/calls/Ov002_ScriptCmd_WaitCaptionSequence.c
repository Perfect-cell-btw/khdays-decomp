/* Script command: done (1) once the pending caption sequence has finished. */

extern int Ov002_UpdatePendingCaptionSequence();

int Ov002_ScriptCmd_WaitCaptionSequence(int arg0) {
    if (Ov002_UpdatePendingCaptionSequence(arg0) != 0) {
        return 0;
    }
    return 1;
}
