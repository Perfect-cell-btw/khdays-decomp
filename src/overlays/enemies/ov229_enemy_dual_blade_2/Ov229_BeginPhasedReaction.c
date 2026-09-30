/* Init the multi-part reaction: reset the sub-state bytes (+0x1c6=0, +0x1c7=-1), point
 * (child)+0xc at (*child)+0xb0, raise flag 6 in the high byte at (*child)+0x60, then
 * register the three phase handlers on slots 1, 0 and 2. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov229_stSetFlags86Clear3ac(int);
extern void Ov229_AiDispatchAction(int);
extern void Ov229_AiIntegrateMotion(int);
void Ov229_BeginPhasedReaction(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(signed char *)(*(int *)child + 0x1c6) = 0;
    *(signed char *)(*(int *)child + 0x1c7) = -1;
    *(int *)(child + 0xc) = *(int *)child + 0xb0;
    {
        unsigned short *p = (unsigned short *)(*(int *)child + 0x60);
        unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
        hi |= 6;
        *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
    }
    SetIndexedSlot(param_1, 1, (void *)&Ov229_stSetFlags86Clear3ac);
    SetIndexedSlot(param_1, 0, (void *)&Ov229_AiDispatchAction);
    SetIndexedSlot(param_1, 2, (void *)&Ov229_AiIntegrateMotion);
}
