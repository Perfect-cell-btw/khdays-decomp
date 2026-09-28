/* Clears *arg1=0; if the slot at *globalData+0x2c2c+0x550 is nonzero, releases it via
 * SoundSeqHandle_Stop and clears it. */

extern int data_ov094_020bc240;
extern void SoundSeqHandle_Stop();

void Ov094_ReleaseGlobalSlotIfSet(int this_, int arg1) {
    int *base = (int *)(data_ov094_020bc240 + 0x2c2c);
    *(int *)arg1 = 0;
    if (base[0x154] != 0) {
        SoundSeqHandle_Stop(base[0x154]);
        base[0x154] = 0;
    }
}
