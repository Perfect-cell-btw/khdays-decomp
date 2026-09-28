/* Post a 4-byte sprite request (template halfword-pair with the live tile id), kick anim 5,
 * then dispatch 020d09ac. */
extern int func_02031384(int, void *, int);
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int data_ov277_020d36bc;
extern int Ov277_AiChargeStart(int);
struct hpair { unsigned short a, b; };
void Ov277_AiEnterCharge(int param_1) {
    int owner = *(int *)(param_1 + 4);
    struct hpair buf = *(struct hpair *)&data_ov277_020d36bc;
    buf.a = *(unsigned short *)(*(int *)owner + 2);
    func_02031384(4, &buf, 4);
    Ov107_PostTagUpdate(*(int *)owner, 5, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov277_AiChargeStart);
}
