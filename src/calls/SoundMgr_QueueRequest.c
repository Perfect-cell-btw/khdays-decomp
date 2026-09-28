extern unsigned char *data_0204c234;
extern unsigned char *SoundMgr_PeekQueued(int arg);
extern void ScriptQueue_Push(int arg0, int arg1, int arg2);

void SoundMgr_QueueRequest(int kind, int arg1, int arg2) {
    unsigned char *ptr;

    if (*(short *)(data_0204c234 + 0xb46f6) == arg1) {
        return;
    }

    ptr = SoundMgr_PeekQueued(0);
    if (ptr == 0 || ptr[0] != kind) {
        ScriptQueue_Push(kind, arg1, (unsigned short)arg2);
        return;
    }

    ptr[1] = arg1;
    *(unsigned short *)(ptr + 2) = arg2;
}
