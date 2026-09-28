/* Moves the BGM player's volume to the target over the frames and records the target volume. */

extern int data_0204c234;
extern void NNS_SndPlayerMoveVolume();

void InvokeSubStructAndStampByte(int arg0, int arg1) {
    NNS_SndPlayerMoveVolume(data_0204c234 + 0xb44c4, arg0, arg1);
    *(unsigned char *)(data_0204c234 + 0xb46fd) = arg0;
}
