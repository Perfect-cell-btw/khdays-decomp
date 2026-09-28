/* Begin the leap: flag the owner charging bit (*node+0x388), set the hw60 high-byte "airborne"
 * bit 1, fire the leap motion command (Ov107_BuildAndSendUpdate, anim 0x14d speed 0xf), clear node[9],
 * and register the think callback. */
extern void Ov107_BuildAndSendUpdate(int owner, int anim, int speed, int arg);
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov227_DriftTick(void);

void Ov227_StartLeap(int param_1) {
    int *node = *(int **)(param_1 + 4);
    unsigned short hw60;
    *(int *)(*node + 0x388) = 1;
    hw60 = *(unsigned short *)(*node + 0x60);
    *(unsigned short *)(*node + 0x60) =
        (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 1) << 0x18) >> 0x10);
    Ov107_BuildAndSendUpdate(*node, 0x14d, 0xf, node[1]);
    node[9] = 0;
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), &Ov227_DriftTick);
}
