/* Bail via 020cc900 if not ready; else latch +0x10 into +0xc, kick anim 4, notify 020cc8ec, dispatch. */
extern int Ov218_DistanceToTarget(int);
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov218_startAnim(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov218_ThrowWindupTick(int);
void Ov218_AiEnterAnim4IfTarget(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov218_DistanceToTarget(param_1) < 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
        return;
    }
    *(int *)(owner + 0xc) = *(int *)(owner + 0x10);
    Ov107_PostTagUpdate(*(int *)owner, 4, 0);
    Ov218_startAnim(*(int *)owner, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov218_ThrowWindupTick);
}
