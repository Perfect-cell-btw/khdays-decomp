/* Build the sprite request (mirroring the object's facing) and dispatch. */
extern void func_02031384(int a, void *req, int b);
extern int SetIndexedSlot(int, int, void *);
extern int data_ov253_020d4964;
extern int Ov253_AiPickupFollow(int);
struct hpair { unsigned short a, b; };
void Ov253_AiPostPickupMessage(int param_1) {
    int owner = *(int *)(param_1 + 4);
    struct hpair buf = *(struct hpair *)((char *)&data_ov253_020d4964 + 0xc);
    buf.a = *(unsigned short *)(*(int *)owner + 2);
    func_02031384(4, &buf, 4);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_AiPickupFollow);
}
