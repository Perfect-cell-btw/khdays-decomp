/* Notify 020cd128, advance +0x44 by the frame delta; once it passes 0x3850 (once only) fire the
 * 0x16d/6 effect; then unless busy kick anim 0x14, retire the +0x468 node, clear +0x40 and dispatch. */
extern int Ov254_TrackTargetFlatDistance(int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov254_ForwardToAiIfReady_3(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov254_AiLoopAnimThenRelease(int);
void Ov254_AiWindupTrackTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov254_TrackTargetFlatDistance(param_1);
    *(int *)(owner + 0x44) += *(int *)(*(int *)param_1 + 0x2c);
    int f = *(unsigned char *)(owner + 0x70);
    if ((f & 1) == 0) {
        if (*(int *)(owner + 0x44) >= 0x3850) {
            *(unsigned char *)(owner + 0x70) = f | 1;
            Ov107_BuildAndSendUpdate(*(int *)owner, 0x16d, 6, *(int *)(owner + 8));
        }
    }
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 0x14, 0);
    Ov254_ForwardToAiIfReady_3(*(int *)(*(int *)owner + 0x468));
    *(int *)(owner + 0x40) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov254_AiLoopAnimThenRelease);
}
