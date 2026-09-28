/* Resets the supplied controller state and releases the scene-global slot at +0x550 when present.
 */

extern int data_ov077_020b9b80;
extern void SoundSeqHandle_Stop();

void Ov077_ReleaseGlobalSlotIfSet(int this_, int arg1) {
    int *base = (int *)(data_ov077_020b9b80 + 0x2c2c);
    *(int *)arg1 = 0;
    if (base[0x154] != 0) {
        SoundSeqHandle_Stop(base[0x154]);
        base[0x154] = 0;
    }
}
