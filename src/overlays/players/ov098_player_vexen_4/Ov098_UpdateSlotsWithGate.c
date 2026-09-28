/* Drops the effect block when the character leaves the guard state, and advances the seven effect
 * slots. */

extern int Ov022_IsState9Or6WithFlag200(int a);
extern void Ov098_ClearState1IfReady(int a, int b);

typedef struct {
    char pad0[0x464];
    unsigned long long flags;
} Self;

void Ov098_UpdateSlotsWithGate(Self *self, int *node, int arg) {
    int i;
    char *p;
    if (node[0] != 0 && (self->flags & 0x10000ULL) == 0) {
        if (Ov022_IsState9Or6WithFlag200((int)self + 0x2f8 + 0x2000) == 0) node[0] = 0;
    }
    p = (char *)node + 0x14;
    for (i = 0; i < 7; i++, p += 0x10c) {
        Ov098_ClearState1IfReady((int)p, arg);
    }
}
