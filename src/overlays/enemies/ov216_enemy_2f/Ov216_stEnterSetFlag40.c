/* AI step: when the model's animation ends, sets bit 0x40 in the high byte of the actor's flags,
 * posts pose 4, resets the pose vectors for the launch and installs the charge-launch step. */

struct hw60 { unsigned short lo : 8, hi : 8; };
extern void Ov107_PostTagUpdate();
extern void Ov216_loadDefaultPoseVecs();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov216_StepChargeLaunch(void);

void Ov216_stEnterSetFlag40(int *node) {
    int *state = (int *)node[1];
    if (*(unsigned char *)(state[1] + 0xad) != 0) return;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    }
    Ov107_PostTagUpdate(*state, 4, 1);
    Ov216_loadDefaultPoseVecs(*state, 1);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov216_StepChargeLaunch);
}
