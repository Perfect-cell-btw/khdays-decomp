/* Unless busy, arm the 020c5af8 timer, run 020ce36c, kick anim (7, phase 1), then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov212_ResetPoseCache(int);
extern int Ov212_IdleTick_2(int);
void Ov212_AiIdleStart(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_BuildAndSendUpdate(*(int *)owner, 0x128, 0xb, *(int *)(owner + 8));
    Ov212_ResetPoseCache(owner);
    Ov107_PostTagUpdate(*(int *)owner, 7, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov212_IdleTick_2);
}
