/* Skip if the grandchild busy flag (+0xad) is set; else set anim 0x12 and dispatch. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov227_AiRecoilTurnStart(void);
void Ov227_AiRecoilTurnWait(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)child, 0x12, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov227_AiRecoilTurnStart);
}
