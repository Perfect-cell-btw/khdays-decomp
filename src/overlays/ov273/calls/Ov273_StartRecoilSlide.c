/* Begin the recoil slide: flag the owner charging bit (*node+0x390), clear the hw60 high-byte
 * "grounded" bit 0x80, roll a random slide duration into node[2], and register the think callback. */
extern int RandNextScaled();
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov273_AiCountdownToSlam(void);

void Ov273_StartRecoilSlide(int param_1) {
    int *node = *(int **)(param_1 + 4);
    int v;
    unsigned short hw60;
    *(int *)(*node + 0x390) = 1;
    hw60 = *(unsigned short *)(*node + 0x60);
    *(unsigned short *)(*node + 0x60) =
        (hw60 & ~0xff00) | ((unsigned int)(unsigned short)(((unsigned int)hw60 << 0x10) >> 0x18 & 0xffffff7f) << 0x18 >> 0x10);
    node[2] = RandNextScaled(0x801) + (v - v);
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), &Ov273_AiCountdownToSlam);
}
