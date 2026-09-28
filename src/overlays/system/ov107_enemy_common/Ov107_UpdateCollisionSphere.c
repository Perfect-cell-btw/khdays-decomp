/* Recomputes the node's world collision sphere and its AABB from the local sphere. */

extern void VEC_Add(int *a, int *b, int *out);
extern void SphereToAABB(int *aabb, int *sphere);

void Ov107_UpdateCollisionSphere(int node) {
    VEC_Add((int *)(node + 0xb0), (int *)(node + 100), (int *)(node + 0x74));
    *(int *)(node + 0x80) = *(int *)(node + 0x70);
    SphereToAABB((int *)(node + 0x84), (int *)(node + 0x74));
}
