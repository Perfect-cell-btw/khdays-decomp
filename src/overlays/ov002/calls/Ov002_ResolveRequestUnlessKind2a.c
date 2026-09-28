/* Resolve the request unless it is kind 0x2a, and only while
 * Ov002_Field_GetState reports the subsystem free. Reports 0 otherwise. */
extern int LoadGlobalU16At0(int req);
extern int Ov002_Field_GetState(void);
extern int Ov002_CopySourceBlock(int req);

int Ov002_ResolveRequestUnlessKind2a(int req) {
    int result = 0;

    if (LoadGlobalU16At0(req) == 0x2a) {
        return 0;
    }
    if (Ov002_Field_GetState() == 0) {
        result = Ov002_CopySourceBlock(req);
    }
    return result;
}
