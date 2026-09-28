/* Reset the child sprite (anim 0x10), scroll its +0x14 vector by -0x600,
 * clear +0x75/+0x5c, then dispatch via SetIndexedSlot (handler Ov227_AiRecoilTurnWait). */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void ScaleVec3Fx12(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov227_AiRecoilTurnWait(void);
void Ov227_AiEnterRecoilTurn(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)child, 0x10, 0);
    ScaleVec3Fx12(-0x600, child + 0x14, child + 0x14);
    *(unsigned char *)(child + 0x75) = 0;
    *(int *)(child + 0x5c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov227_AiRecoilTurnWait);
}
