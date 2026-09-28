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
