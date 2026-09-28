extern void Ov107_StartAnim();
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov202_stateTransformAimVec(void);

void Ov202_stateSetFlagEffect(char *obj) {
    int *state = *(int **)(obj + 4);
    unsigned int h = *(unsigned short *)(*state + 0x60);
    unsigned int masked = h & ~0xff00;
    *(unsigned short *)(*state + 0x60) =
        masked | (((((h << 0x10) >> 0x18) | 0x40) << 0x18) >> 0x10);
    Ov107_StartAnim(*(void **)(*state + 0x388), 0, 0, masked);
    Ov107_PostTagUpdate(*state, 4, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov202_stateTransformAimVec);
}
