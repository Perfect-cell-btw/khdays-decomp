/* Looks up the head request; if it is already kind 3 the halfword at +2 is overwritten in place,
 * otherwise a new kind-3 request is pushed with the same value. Twelve callers. */

extern unsigned char *SoundMgr_PeekQueued(int arg);
extern void ScriptQueue_Push(int arg0, int arg1, int arg2);

void RequestQueue_SetOrPushKind3(int arg) {
    unsigned char *ptr = SoundMgr_PeekQueued(0);

    if (ptr == 0 || ptr[0] != 3) {
        ScriptQueue_Push(3, 0, (unsigned short)arg);
        return;
    }

    *(unsigned short *)(ptr + 2) = arg;
}
