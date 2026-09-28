/* Recomputes the node's world collision sphere and its AABB from the local sphere. Returns the box.
 */

extern void VEC_Add(int *a, int *b, int *out);
extern int SphereToAABB(int *aabb, int *sphere);

int Ov107_UpdateCollisionSphere(int node) {
    VEC_Add((int *)(node + 0xb0), (int *)(node + 100), (int *)(node + 0x74));
    *(int *)(node + 0x80) = *(int *)(node + 0x70);
    return SphereToAABB((int *)(node + 0x84), (int *)(node + 0x74));
}
