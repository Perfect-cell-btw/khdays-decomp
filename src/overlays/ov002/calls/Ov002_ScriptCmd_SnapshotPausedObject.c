extern int ByteCode_ResolveOperand();
extern int Ov002_SnapshotPausedObject();

int Ov002_ScriptCmd_SnapshotPausedObject(int arg0) {
    ByteCode_ResolveOperand(arg0);
    Ov002_SnapshotPausedObject();
    return 1;
}
