/* Enter the ov125 enemy's charge: clear bit 0 and set bits 1-2 of the hw60 high byte, drop
 * bit 0 of the +0x388 target's +8 word, request animation 0x49 with the +0x24 blend, reset the
 * +0x2c timer and register the charge think callback. */
struct hw60 { unsigned short lo : 8, hi : 8; };
struct w8 { unsigned int lo : 8, rest : 24; };

extern void Ov107_BuildAndSendUpdate(int owner, int a, int anim, int blend);
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov126_TickRecovery(void);

void Ov126_EnterCharge(int self) {
    int *node = *(int **)(self + 4);
    ((struct hw60 *)(*node + 0x60))->hi &= ~1;
    ((struct hw60 *)(*node + 0x60))->hi |= (unsigned char)6;
    ((struct w8 *)(*(int *)(*node + 0x388) + 8))->lo &= ~1;
    Ov107_BuildAndSendUpdate(*node, 0, 0x49, node[9]);
    node[0xb] = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov126_TickRecovery);
}
