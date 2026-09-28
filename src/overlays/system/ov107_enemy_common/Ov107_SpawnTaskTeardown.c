/* Tail-call 02033e48 with the +0x10 field of *(param+4). */
extern int SoundSeqHandle_Stop(int);
int Ov107_SpawnTaskTeardown(int param_1) {
    return SoundSeqHandle_Stop(*(int *)(*(int *)(param_1 + 4) + 0x10));
}
