/* Return tick of an ov259 helper: once grounded (+0x17a bit 0) +0x34 and the +0x38 flag clear, the
 * +0x394 owner is knocked back at the helper's +0x74 position (mode 0xe), sound 0x172/0x14 fires at
 * the +8 point and the node moves on to 020d2498. In flight the +0xc velocity heads for the +0x38c
 * anchor's first point at 0.875 and the flight step runs (020d1cc4). */
typedef unsigned char u8;
typedef struct { int x, y, z; } Vec3;
struct Flag17a { u8 b0 : 1; };

extern void func_ov107_020c0b90(int owner, int mode, Vec3 at, int flag);
extern void Ov259_PlaySound(int actor, int id, int variant, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(Vec3 *v, Vec3 *out);
extern void ScaleVec3Fx12(int scale, Vec3 *v, Vec3 *d);
extern void Ov259_HelperFlightStep(int *node);
extern void Ov259_HelperSweepTick(void);

void Ov259_HelperReturnTick(int *node)
{
    int *state = (int *)node[1];

    if (((struct Flag17a *)(*state + 0x17a))->b0) {
        state[0xd] = 0;
        *((u8 *)state + 0x38) = 0;
        func_ov107_020c0b90(*(int *)(*state + 0x394), 0xe, *(Vec3 *)(*state + 0x74), 0);
        Ov259_PlaySound(*(int *)(*state + 0x394), 0x172, 0x14, (void *)state[2]);
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov259_HelperSweepTick);
        return;
    }
    VEC_Subtract((Vec3 *)(**(int **)(*state + 0x38c) + 4), (Vec3 *)(*state + 0x74), (Vec3 *)(state + 3));
    VEC_Normalize((Vec3 *)(state + 3), (Vec3 *)(state + 3));
    ScaleVec3Fx12(0xe00, (Vec3 *)(state + 3), (Vec3 *)(state + 3));
    Ov259_HelperFlightStep(node);
}
