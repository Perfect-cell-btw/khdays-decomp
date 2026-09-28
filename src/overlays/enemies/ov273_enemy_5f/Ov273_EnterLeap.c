/* Leap entry: dir = normalised (anchor(+4) - owner(+0x384)->+0x74); side = a random-handed cross
 * of dir with the up vector (data_02042240 / data_02042264). Marks the owner's +0x390 flag,
 * snapshots the anchor into +0x30, lands the +0x3c target 0x8000 along dir from the anchor,
 * sets the +0x40 height to owner+0x78 - (actor's +0x384)->+0x13c + 0x1000, seeds the +0x18 lift
 * with 0xa000 up, builds the +0x24 velocity as 0x28000 along normalised (dir + side), clears the
 * +0x14 timer and moves the node to 020d1f60. */
struct v3 { int x, y, z; };
extern void VEC_Subtract(void *a, void *b, void *c);
extern int  VEC_Normalize(void *v, void *out);
extern int  RandNextScaled();  /* K&R decl: needed for the rand `+ (v - v)` copy artifact */
extern void VEC_CrossProduct(void *a, void *b, void *d);
extern void ScaleVec3Fx12(int s, void *v, void *d);
extern void VEC_Add(void *a, void *b, void *d);
extern void SetIndexedSlot(int self, int idx, int cb);
extern int  data_02042240;
extern int  data_02042264;
extern void Ov273_LeapTick(void);

void Ov273_EnterLeap(int *self) {
    int owner;
    int *state = (int *)self[1];
    int dir[3];
    int side[3];
    int v;

    owner = *(int *)(*state + 0x384);
    VEC_Subtract((void *)state[1], (void *)(owner + 0x74), dir);
    VEC_Normalize(dir, dir);
    if (RandNextScaled(2) + (v - v) != 0) {
        VEC_CrossProduct(&data_02042240, dir, side);
    } else {
        VEC_CrossProduct(&data_02042264, dir, side);
    }
    *(int *)(*state + 0x390) = 1;
    *(struct v3 *)(state + 0xc) = *(struct v3 *)state[1];
    ScaleVec3Fx12(0x8000, dir, state + 0xf);
    VEC_Add((void *)state[1], state + 0xf, state + 0xf);
    state[0x10] = *(int *)(owner + 0x78) - *(int *)(*(int *)(*state + 0x384) + 0x13c) + 0x1000;
    ScaleVec3Fx12(0xa000, &data_02042240, state + 6);
    VEC_Add(dir, side, state + 9);
    VEC_Normalize(state + 9, state + 9);
    ScaleVec3Fx12(0x28000, state + 9, state + 9);
    state[5] = 0;
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), (int)&Ov273_LeapTick);
}
