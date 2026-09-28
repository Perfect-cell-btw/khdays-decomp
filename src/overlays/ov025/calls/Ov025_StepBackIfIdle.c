extern void Ov025_MissionMenuStep();
extern void PlaySound();

void Ov025_StepBackIfIdle(int arg0, int arg1, int arg2, int arg3) {
    unsigned char b;
    if (*(int *)(arg0 + 0x158) != 0) return;
    if (*(int *)(arg0 + 0x180) != 0) return;
    b = *(unsigned char *)(arg0 + 0x17a);
    if (b > 1 && (b = *(unsigned char *)(arg0 + 0x178)) > 1) {
        Ov025_MissionMenuStep(arg0, -1, arg2, arg3);
        PlaySound(0, 2);
    }
}
