/* Records the three fields of the pending request at +0xb46ec of the block held by
 * gSoundMgr; each write re-reads the block pointer as the ROM does. */
extern char *gSoundMgr;

void Req_SetPendingFields(int a, int b, int c) {
    *(int *)(gSoundMgr + 0xb46ec) = a;
    *(int *)(gSoundMgr + 0xb46f0) = b;
    *(short *)(gSoundMgr + 0xb46f4) = (short)c;
}
