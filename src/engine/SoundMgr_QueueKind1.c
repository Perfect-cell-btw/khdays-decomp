/* Queues a sound request of kind 1 with the value, updating a queued request of that kind instead
 * when there is one; returns 1. */

extern unsigned char *SoundMgr_PeekQueued(int arg);
extern void ScriptQueue_Push(int arg0, int arg1, int arg2);

int SoundMgr_QueueKind1(int arg) {
    unsigned char *ptr = SoundMgr_PeekQueued(0);

    if (ptr == 0 || ptr[0] != 1) {
        ScriptQueue_Push(1, arg, 0);
    } else {
        ptr[1] = arg;
    }

    return 1;
}
