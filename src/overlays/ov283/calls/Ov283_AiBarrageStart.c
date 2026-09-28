/* Unless busy, fire effect 0x173 on the linked node, kick anim 9, clear the +0x68/+0x6c/+0x48/
 * +0x74 block and dispatch 020cdf1c. */
extern int Ov283_PostItemUpdate(int, int, int, int);
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov283_BarrageTick(int);
void Ov283_AiBarrageStart(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov283_PostItemUpdate(*(int *)owner, 0x173, 7, *(int *)(owner + 8));
    Ov107_PostTagUpdate(*(int *)owner, 9, 0);
    *(int *)(owner + 0x68) = 0;
    *(int *)(owner + 0x6c) = 0;
    *(int *)(owner + 0x48) = 0;
    *(int *)(owner + 0x74) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov283_BarrageTick);
}
