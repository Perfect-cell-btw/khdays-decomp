/* Moves the BGM player's volume to the target over the frames and records the target volume. */

extern int gSoundMgr;
extern void NNS_SndPlayerMoveVolume();

void InvokeSubStructAndStampByte(int arg0, int arg1) {
    NNS_SndPlayerMoveVolume(gSoundMgr + 0xb44c4, arg0, arg1);
    *(unsigned char *)(gSoundMgr + 0xb46fd) = arg0;
}
