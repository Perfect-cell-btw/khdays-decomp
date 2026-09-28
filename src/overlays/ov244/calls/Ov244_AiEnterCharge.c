/* Build the sprite request (mirroring facing), kick anim 5, then dispatch. */
extern void func_02031384(int a, void *req, int b);
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int data_ov244_020d3724;
extern int Ov244_AiChargeStart(int);
struct hpair { unsigned short a, b; };
void Ov244_AiEnterCharge(int param_1) {
    int owner = *(int *)(param_1 + 4);
    struct hpair buf = *(struct hpair *)&data_ov244_020d3724;
    buf.a = *(unsigned short *)(*(int *)owner + 2);
    func_02031384(4, &buf, 4);
    Ov107_PostTagUpdate(*(int *)owner, 5, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov244_AiChargeStart);
}
