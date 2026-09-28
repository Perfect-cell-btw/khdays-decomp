/* Requests a BGM change when the selection differs from the current one (or a change is forced):
 * updates a queued change request or pushes a new one; returns 1. */

extern int data_0204c234;
extern unsigned char *SoundMgr_PeekQueued(int a);
extern void ScriptQueue_Push(int a, int b, int c);

int SetSelectionIfChanged(int param_1) {
    int base = data_0204c234;
    if (*(short *)(base + 0xb46f6) != param_1 ||
        *(unsigned char *)(base + 0xb479e) == 1) {
        unsigned char *p = SoundMgr_PeekQueued(0);
        if (p == 0 || *p != 2) {
            ScriptQueue_Push(2, param_1, 0);
        } else {
            p[1] = (unsigned char)param_1;
        }
    }
    return 1;
}
