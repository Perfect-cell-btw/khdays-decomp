/* Ov245_GlideTick_2 -- glide tick: copies the +0x34 drift into the +0x1c direction and scales
 * the drift by 0.6875 in place; once the +4 item's animation is idle (+0xad) and the actor is
 * grounded (bit 0 of +0x17a or +0x17c) with a drift shorter than 16 units, requests sub-state 2
 * and releases the node's slot. */
typedef struct { int x, y, z; } Vec3;
struct Bit0 { unsigned char bit0 : 1; };

extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern int VEC_Mag(const Vec3 *v);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov245_GlideTick_2(int *node) {
    int *state = (int *)node[1];

    *(Vec3 *)(state + 7) = *(Vec3 *)(state + 0xd);
    ScaleVec3Fx12(0xb00, (Vec3 *)(state + 0xd), (Vec3 *)(state + 0xd));
    if (*(unsigned char *)(state[1] + 0xad) != 0) {
        return;
    }
    if (!((struct Bit0 *)(*state + 0x17a))->bit0 && !((struct Bit0 *)(*state + 0x17c))->bit0) {
        return;
    }
    if (VEC_Mag((Vec3 *)(state + 0xd)) > 0x10) {
        return;
    }
    *(unsigned char *)(*state + 0x1c7) = 2;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
