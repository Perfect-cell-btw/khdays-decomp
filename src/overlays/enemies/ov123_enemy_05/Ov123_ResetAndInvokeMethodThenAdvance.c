struct u16pair { unsigned short a, b; };

extern void Ov107_PostTagUpdate(int obj, int a, int b);
extern void SetIndexedSlot(int obj, int a, int cb);
extern short data_ov123_020ce2ac;
extern void Ov123_ShotWindup(void);

// Reset the node's timers, switch to mode 3, then hand the default parameter pair
// (data_ov123_020ce2ac) to the object's installed method before advancing.
void Ov123_ResetAndInvokeMethodThenAdvance(int *this)
{
    int node = this[1];
    struct u16pair params;
    void (*method)(int, struct u16pair *, int);
    *(int *)(node + 0x20) = 0;
    Ov107_PostTagUpdate(*(int *)node, 3, 0);
    *(int *)(node + 0x28) = 0;
    *(int *)(node + 0x2c) = 0;
    params = *(struct u16pair *)&data_ov123_020ce2ac;
    method = *(void (**)(int, struct u16pair *, int))(*(int *)node + 0x24);
    if (method != 0) {
        method(*(int *)node, &params, 4);
    }
    SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), (int)&Ov123_ShotWindup);
}
