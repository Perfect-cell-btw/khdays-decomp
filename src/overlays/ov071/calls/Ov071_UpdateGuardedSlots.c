extern int Ov022_IsState9Or6WithFlag200(int a);
extern void MI_Copy48B(int dst, int src);
extern int Sequence_UpdateTracks(int a, int b);
extern void Ov071_ClearStateIfReadyWhenActive(int a, int b);

typedef struct {
    char pad0[0x464];
    unsigned long long flags;
    char pad46c[0x2aba - 0x46c];
    short f2aba;
} Self;

void Ov071_UpdateGuardedSlots(Self *self, int *node) {
    int i;
    char *p;
    if (node[0] == 2 && (self->flags & 0x10000ULL) == 0) {
        if (Ov022_IsState9Or6WithFlag200((int)self + 0x2f8 + 0x2000) == 0) node[0] = 0;
    }
    if (node[0] == 1) {
        MI_Copy48B((int)self + 0x158 + 0x400, (int)node + 0x8c);
        if (Sequence_UpdateTracks((int)node + 0xc, self->f2aba) != 0) {
            node[0] = 2;
        }
    }
    for (i = 0, p = (char *)node + 0x118; i < 6; i++, p += 0x110) {
        Ov071_ClearStateIfReadyWhenActive((int)p, self->f2aba);
    }
}
