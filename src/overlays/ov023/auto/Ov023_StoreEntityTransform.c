typedef struct { int x, y, z; } Vec3;
/* Store a 3-word vector (vec) into obj+0x15c0 and a 2-word pair (a,b) into obj+0x15d8. */
void Ov023_StoreEntityTransform(int obj, void *vec, int a, int b) {
    *(Vec3 *)(obj + 0x15c0) = *(Vec3 *)vec;
    *(int *)(obj + 0x15d8) = a;
    *(int *)(obj + 0x15dc) = b;
}
