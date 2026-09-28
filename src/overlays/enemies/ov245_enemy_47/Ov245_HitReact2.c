/* Ov245_HitReact2 -- hit reaction (variant with two forwarded arguments): notifies the
 * owner (020c5c54), tells the +0xc callback 0 when bit 1 of +0x40 is set, halts the +0x384
 * item's motion and, in state 1, passes the arguments on to the +0x214 slot (020ceaf8). */
struct Flags40 { int bit0 : 1, bit1 : 1; };

extern void Ov107_MoveNodeAndRelayout(int self, int a);
extern void RefreshObjectCallbacks(int item, int a);
extern void Ov245_StartTwoPointMove(int slot, int b, int c);

void Ov245_HitReact2(int self, int a, int b, int c) {
    Ov107_MoveNodeAndRelayout(self, a);
    if (((struct Flags40 *)(self + 0x40))->bit1 && *(void (**)(int, int))(self + 0xc) != 0) {
        (*(void (**)(int, int))(self + 0xc))(self, 0);
    }
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    if (*(int *)(self + 0x50) == 1) {
        Ov245_StartTwoPointMove(*(int *)(self + 0x214), b, c);
    }
}
