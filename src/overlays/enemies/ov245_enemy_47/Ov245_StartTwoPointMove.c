typedef struct { int x, y, z; } Vec3;

/* Starts a two-point move: marks the owner busy, stores both endpoints and sets phase 1. */
void Ov245_StartTwoPointMove(int *self, Vec3 *from, Vec3 *to) {
    *(int *)(*self + 0x38c) = 1;
    *(Vec3 *)((char *)self + 0x18) = *from;
    *(Vec3 *)((char *)self + 0x24) = *to;
    *(char *)(*self + 0x1c7) = 1;
}
