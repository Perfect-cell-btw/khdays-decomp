/* Ov253_SubStateDispatch -- sub-state dispatcher: when a sub-state (+0x1c7) is requested, bits 1
 * and 7 of the actor's +0x60 high byte clear, the request becomes the +0x1c6 kind and slot 1
 * takes the matching node (0: 020d2a34, 1-2: 020d2aac, 4: 020d2bac, 5: 020d2f24, 6: 020d3038);
 * the request is then cleared (-1). */
typedef unsigned short u16;

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov253_stSetDispFlags82_2(void);
extern void Ov253_QueueActor_AiEnterWait(void);
extern void Ov253_AiEnterGrow(void);
extern void Ov253_AiEnterPulse(void);
extern void Ov253_SummonEnter(void);

void Ov253_SubStateDispatch(int *node) {
    int *state = (int *)node[1];

    if (*(signed char *)(*state + 0x100 + 0xc7) != -1) {
        {
            u16 hw = *(u16 *)(*state + 0x60);
            *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
                (((unsigned int)(unsigned short)((((unsigned int)hw << 0x10) >> 0x18) & ~0x82) << 0x18) >> 0x10);
        }
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x100 + 0xc7);
        switch (*(signed char *)(*state + 0x100 + 0xc6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov253_stSetDispFlags82_2);
            break;
        case 1:
        case 2:
            SetIndexedSlot(node, 1, Ov253_QueueActor_AiEnterWait);
            break;
        case 3:
            break;
        case 4:
            SetIndexedSlot(node, 1, Ov253_AiEnterGrow);
            break;
        case 5:
            SetIndexedSlot(node, 1, Ov253_AiEnterPulse);
            break;
        case 6:
            SetIndexedSlot(node, 1, Ov253_SummonEnter);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
