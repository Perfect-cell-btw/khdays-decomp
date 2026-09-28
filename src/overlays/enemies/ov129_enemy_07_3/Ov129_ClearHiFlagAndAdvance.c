extern void Ov129_DecaySpinOverElapsed(int self);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov129_PrepSubState2IfChildIdle(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct flag17a { unsigned char b0 : 1; };

void Ov129_ClearHiFlagAndAdvance(int self) {
    int *s = *(int **)(self + 4);
    Ov129_DecaySpinOverElapsed(self);
    if (!((struct flag17a *)(*s + 0x17a))->b0) return;
    ((struct hw60 *)(*s + 0x60))->hi &= ~0x40;
    Ov107_PostTagUpdate(*s, 6, 0);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), (void *)&Ov129_PrepSubState2IfChildIdle);
}
