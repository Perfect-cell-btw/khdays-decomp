/* Unless the grandchild is busy (+0xad), set anim 0x13, run Ov223_startAnim,
 * then dispatch. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov223_startAnim(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov223_TurnTick(void);
void Ov223_AiRecoilTurnStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)child, 0x13, 0);
    Ov223_startAnim(*(int *)child, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov223_TurnTick);
}
