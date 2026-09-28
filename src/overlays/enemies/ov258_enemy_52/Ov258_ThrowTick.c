/* Throw tick of the ov258 actor: the swing hit test runs (020cf6dc) and the +0x34 clock runs up at
 * the frame rate; at 1.0 the pending throw (+0x50 = 1) fires: +0x54 bit 3 is set, the +0x1c point is
 * (0, 15.6, 11.0), the throw sound (+0x58 bank, variant 0x12 with a +0x460 partner else 0x19) and
 * effect 0x2a play there and the actor's +0x428 becomes 7.0. Once the +4 rig is idle the +0x30 timer
 * clears, +0x50 = 1, pose 7 plays and the brain waits on 020cfc20. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec3;

extern void Ov258_SwingHitTest(int *node);
extern void Ov107_BuildAndSendUpdate(int actor, int bank, u16 variant, void *at);
extern void func_ov107_020c0b90(int owner, int mode, Vec3 at, int flag);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov258_SwingTick(void);

void Ov258_ThrowTick(int *node)
{
    int *state = (int *)node[1];

    Ov258_SwingHitTest(node);
    state[0xd] += *(int *)(node[0] + 0x2c);
    if (state[0xd] >= 0x1000 && *(u16 *)(state + 0x14) == 1) {
        (*(u16 *)(state + 0x14))--;
        *((u8 *)state + 0x54) |= 8;
        state[7] = 0;
        state[8] = 0xfa00;
        state[9] = 0xb000;
        Ov107_BuildAndSendUpdate(*state, *(short *)(state + 0x16), *(int *)(*state + 0x460) != 0 ? 0x12 : 0x19, state + 7);
        func_ov107_020c0b90(*state, 0x2a, *(Vec3 *)(state + 7), 0);
        *(int *)(*state + 0x428) = 0x7000;
    }
    if (*(u8 *)(state[1] + 0xad) != 0) {
        return;
    }
    state[0xc] = 0;
    *(u16 *)(state + 0x14) = 1;
    Ov107_PostTagUpdate(*state, 7, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov258_SwingTick);
}
