/* Script command: snapshots the paused object; returns 1. */

extern int ByteCode_ResolveOperand();
extern int Ov002_SnapshotPausedObject();

int Ov002_ScriptCmd_SnapshotPausedObject(int arg0, void *cmd) {
        Ov002_SnapshotPausedObject(ByteCode_ResolveOperand(arg0, cmd));
    return 1;
}
