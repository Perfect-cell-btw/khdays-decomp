extern void Ov107_PostTagUpdate(int obj, int a, int b);
extern void Ov107_StartAnim(int obj, int a, int b);
extern void SetIndexedSlot(int obj, int a, int cb);
extern void Ov281_ApplyAimTransformThenAdvance(void);

// Switch to mode 7, kick the linked effect (node[0][0x3c0]), raise hw60 flag
// 0x40, reset the timer field (node[6]) and advance with the follow-up callback.
void Ov281_EnterMode7KickEffectThenAdvance(int *this)
{
    int node = this[1];
    Ov107_PostTagUpdate(*(int *)node, 7, 0);
    Ov107_StartAnim(*(int *)(*(int *)node + 0x3c0), 1, 0);
    {
        unsigned short *hw = (unsigned short *)(*(int *)node + 0x60);
        unsigned int u = *hw;
        *hw = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    }
    *(int *)(node + 0x18) = 0;
    SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), (int)&Ov281_ApplyAimTransformThenAdvance);
}
