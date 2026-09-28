/* Resets the charge state and releases the associated global slot when present. */

extern int data_ov057_020b74a0;
extern void SoundSeqHandle_Stop();

void Ov057_ReleaseGlobalSlotIfSet(int this_, int arg1) {
    int *base = (int *)(data_ov057_020b74a0 + 0x2c2c);
    *(int *)arg1 = 0;
    if (base[0x154] != 0) {
        SoundSeqHandle_Stop(base[0x154]);
        base[0x154] = 0;
    }
}
