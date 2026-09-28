extern int Collision_CastSphere();

int Ov204_TestSubObjectHelperNonzero(int this_, int arg1) {
    int *s = *(int **)(this_ + 4);
    int val = *(int *)(*(int *)(*s + 4) + 0x7c);
    if (val == 0) goto ret0;
    if (Collision_CastSphere(val, *(int *)((char *)s + 0x24), arg1, 0x800) != 0) return 1;
ret0:
    return 0;
}
