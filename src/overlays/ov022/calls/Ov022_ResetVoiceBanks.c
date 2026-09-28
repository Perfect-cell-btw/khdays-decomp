/* Reset the four banks of three 0x38-byte voices at +0x10 of the root heap.
 * Always reports 0. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov022_StepSyncRequest(void *voice);

int Ov022_ResetVoiceBanks(void) {
    int zero;
    int i;
    int j;
    char *bank;
    char *voice;

    bank = (char *)NNSi_FndGetCurrentRootHeap() + 0x10;
    i = 0;
    zero = i;

    for (; i < 4; i++) {
        j = zero;
        voice = bank;

        for (; j < 3; j++) {
            Ov022_StepSyncRequest(voice);
            voice += 0x38;
        }

        bank += 0xa8;
    }

    return 0;
}
