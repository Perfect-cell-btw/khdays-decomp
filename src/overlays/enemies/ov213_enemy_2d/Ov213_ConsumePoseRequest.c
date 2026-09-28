/* Consume the pending pose request (+0x1c7 of the actor): when one is queued (!= -1) it becomes
 * the current kind (+0x1c6), flags 0x82 are raised in the high byte at +0x60 and kind 0 / 2
 * dispatch slot 1 to 020d289c / 020d2950; the request is then cleared to -1. */
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov213_Minion_AiLockAndResume(void);
extern void Ov213_StartRecoilSlide(void);

void Ov213_ConsumePoseRequest(int self) {
    int obj = *(int *)(self + 4);
    signed char kind = *(signed char *)(*(int *)obj + 0x100 + 0xc7);
    if (kind != -1) {
        *(signed char *)(*(int *)obj + 0x1c6) = kind;
        {
            unsigned short *p = (unsigned short *)(*(int *)obj + 0x60);
            unsigned int hi = ((unsigned int)*p << 0x10) >> 0x18;
            hi |= 0x82;
            *p = (unsigned short)((*p & ~0xff00) | ((hi << 0x18) >> 16));
        }
        switch (*(signed char *)(*(int *)obj + 0x100 + 0xc6)) {
        case 0:
            SetIndexedSlot(self, 1, &Ov213_Minion_AiLockAndResume);
            break;
        case 2:
            SetIndexedSlot(self, 1, &Ov213_StartRecoilSlide);
            break;
        }
    }
    *(signed char *)(*(int *)obj + 0x1c7) = -1;
}
