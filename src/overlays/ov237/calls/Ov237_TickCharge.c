/* Charge tick of the ov237 actor: the +0x30 clock runs up at the frame rate and past 1.99 the charge
 * releases (020cf2b0); once the +4 rig is idle the charge sound (0x12d variant 10) plays at the +0x38
 * point with pose 0x17 and effect 0xb, and the brain waits on 020cf674. */
typedef unsigned char u8;
typedef struct { int x, y, z; } Vec3;

extern void Ov237_ChargeRelease(int *node);
extern void Ov107_BuildAndSendUpdate(int actor, int bank, int variant, int at);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void func_ov107_020c0b90(int owner, int mode, Vec3 at, int flag);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov237_ChargeRepeatTick(void);

void Ov237_TickCharge(int *node)
{
    int *state = (int *)node[1];

    state[0xc] += *(int *)(node[0] + 0x2c);
    if (state[0xc] >= 0x1fe0) {
        Ov237_ChargeRelease(node);
    }
    if (*(u8 *)(state[1] + 0xad) == 0) {
        Ov107_BuildAndSendUpdate(*state, 0x12d, 10, state[0xe]);
        Ov107_PostTagUpdate(*state, 0x17, 0);
        func_ov107_020c0b90(*state, 0xb, *(Vec3 *)state[0xe], 0);
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov237_ChargeRepeatTick);
        return;
    }
}
