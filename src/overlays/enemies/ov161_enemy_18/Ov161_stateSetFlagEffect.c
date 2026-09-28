/* State step: sets bit 0x40 in the high byte of the actor's flags (+0x60), starts the action
 * resource's animation, posts pose 4 and installs the aiming step. */

extern void Ov107_StartAnim();
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov161_stateTransformAimVec(void);
void Ov161_stateSetFlagEffect(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    }
    Ov107_StartAnim(*(int *)(*state + 0x3c8), 0, 0);
    Ov107_PostTagUpdate(*state, 4, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov161_stateTransformAimVec);
}
