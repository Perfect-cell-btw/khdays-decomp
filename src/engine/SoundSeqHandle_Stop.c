/* Stops the sequence a sound handle refers to when the handle is still valid (same serial), and
 * frees the handle's entry. */

extern unsigned char *data_0204c234;
extern void NNS_SndPlayerStopSeq(void *ptr, int value);
extern void ScriptPool_FreeSlot(void *ptr);

void SoundSeqHandle_Stop(unsigned int arg) {
    unsigned char *entry = data_0204c234 + 0xb44e4 + (arg >> 24) * 0x20;

    if (*(unsigned short *)(entry + 0x14) == 0) {
        return;
    }

    if (*(unsigned int *)(entry + 0x18) != (arg & 0x00ffffff)) {
        return;
    }

    NNS_SndPlayerStopSeq(entry + 0x1c, 0);
    ScriptPool_FreeSlot(entry);
}
