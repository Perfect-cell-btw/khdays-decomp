extern int data_ov012_0205cb20;
extern void FrameStep_UpdateTaskQueue();
extern void Ov012_UpdateOpeningBrightness();
extern void SoundMgr_Update();

void Ov012_UpdateOpeningGlobals(void) {
    int base = data_ov012_0205cb20;
    if (base == 0) return;
    if (*(unsigned char *)(base + 0x8be1) != 0) {
        FrameStep_UpdateTaskQueue();
        *(unsigned char *)(data_ov012_0205cb20 + 0x8be1) = 0;
    }
    Ov012_UpdateOpeningBrightness(base);
    SoundMgr_Update();
}
