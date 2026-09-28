/* Copy the working Vec3 after decrementing the node timer, guard on the actor bit, run
 * pose/subaction setup, and advance to the next state callback. */

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

extern void Ov107_PostTagUpdate(int obj, int a, int b);
extern void Ov107_StartAnim(int obj, int a, int b);
extern void SetIndexedSlot(void *node, int idx, void *next);
extern void Ov121_ReaimStrafe(void);

void Ov121_CopyVecThenSetupSubActionAndAdvance(int *node) {
    int *state = (int *)node[1];
    state[0xb] -= 0x100;
    *(Vec3 *)(state + 7) = *(Vec3 *)(state + 10);
    if (((unsigned int)(*(unsigned char *)(*state + 0x17a) << 0x1f) >> 0x1f) == 0) return;
    Ov107_PostTagUpdate(*state, 8, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3a0), 2, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov121_ReaimStrafe);
}
