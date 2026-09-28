/* hw60 `hi &= ~0x80` takes the BITFIELD form and the `|= 1` at +8 the byte bitfield;
 * Ov107_PostTagUpdate takes three arguments (Ghidra shows five). */
typedef struct { unsigned short lo : 8, hi : 8; } Hw60;
typedef struct { unsigned int lo : 8, rest : 24; } Byte8;
extern void Ov107_PostTagUpdate(int owner, int a, int b);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov148_AimAtTargetAfterWindup(void);

void Ov148_ClearMoveTimerAndFire(int *self) {
    int *obj = (int *)self[1];
    int t;

    t = obj[0x10] + *(int *)(self[0] + 0x2c);
    obj[0x10] = t;
    if (t < 0x6ee) {
        return;
    }
    ((Hw60 *)(*obj + 0x60))->hi &= ~0x80;
    *(unsigned short *)(*obj + 0x1ae) &= ~1;
    ((Byte8 *)(*(int *)(*obj + 0x38c) + 8))->lo |= 1;
    Ov107_PostTagUpdate(*obj, 0, 0);
    obj[0x10] = 0;
    *(signed char *)((int)obj + 0x45) = 0;
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), &Ov148_AimAtTargetAfterWindup);
}
