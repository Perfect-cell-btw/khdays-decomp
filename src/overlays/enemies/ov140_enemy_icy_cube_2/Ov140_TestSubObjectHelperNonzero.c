/* Whether a sphere cast from the stored position hits the world collision of the actor's owner. */

extern int Collision_CastSphere();

int Ov140_TestSubObjectHelperNonzero(int this_, int arg1) {
    int *s = *(int **)(this_ + 4);
    int val = *(int *)(*(int *)(*s + 4) + 0x7c);
    if (val == 0) goto ret0;
    if (Collision_CastSphere(val, *(int *)((char *)s + 0x4c), arg1, 0x10) != 0) return 1;
ret0:
    return 0;
}
