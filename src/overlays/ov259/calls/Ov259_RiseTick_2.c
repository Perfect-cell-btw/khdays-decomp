/* Rise tick of the ov259 actor: the +0x68 timer accumulates the frame rate, the aim refreshes
 * (020cdcac) and the +0x14 drift decays by 0x1d00. Once the partner holds no queued move the actor is
 * knocked back at the +0x10 point (mode 9), the drift clears, it is placed at (-4, 10, -30), bit 6
 * of the +0x60 high byte is set, pose 2 loops on the actor and its partner, the timer restarts, sound
 * 0x172/0x23 fires at the +0x10 point, it is knocked back again (mode 0xc) and the node moves on to
 * 020d0f88. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec3;

extern void Ov259_RefreshAim(int *node);
extern void ScaleVec3Fx12(int scale, Vec3 *v, Vec3 *d);
extern void func_ov107_020c0b90(int owner, int mode, Vec3 at, int flag);
extern void Ov107_MoveNodeAndRelayout(int actor, Vec3 *at);
extern void Ov107_PostTagUpdate(int actor, int pose, int loop);
extern void Ov259_MirrorPartnerPose(int *node, int pose, int mode);
extern void Ov259_PlaySound(int actor, int id, int variant, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov259_ChargeTick(void);
extern const Vec3 data_02041dc8;

void Ov259_RiseTick_2(int *node)
{
    int *state = (int *)node[1];
    Vec3 pos;

    state[0x1a] += *(int *)(node[0] + 0x2c);
    Ov259_RefreshAim(node);
    ScaleVec3Fx12(0x1d00, (Vec3 *)(state + 5), (Vec3 *)(state + 5));
    if (*(u8 *)(state[1] + 0xad) != 0) {
        return;
    }
    func_ov107_020c0b90(*state, 9, *(Vec3 *)state[4], 0);
    pos.x = -0x4000;
    pos.y = 0xa000;
    pos.z = -0x1e000;
    *(Vec3 *)(state + 5) = data_02041dc8;
    Ov107_MoveNodeAndRelayout(*state, &pos);
    {
        u16 hw = *(u16 *)(*state + 0x60);
        *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x40) << 0x18) >> 0x10);
    }
    Ov107_PostTagUpdate(*state, 2, 1);
    Ov259_MirrorPartnerPose(node, 2, 1);
    state[0x1a] = 0;
    Ov259_PlaySound(*state, 0x172, 0x23, (void *)state[4]);
    func_ov107_020c0b90(*state, 0xc, *(Vec3 *)state[4], 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov259_ChargeTick);
}
