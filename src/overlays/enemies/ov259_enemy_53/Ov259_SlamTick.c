/* Slam tick of the ov259 actor: the +0x68 timer accumulates the frame rate, the ground test
 * (020cdc20) zeroes the x/z drift once grounded and the aim refreshes. At 0xc38 the impact lands once
 * (+0x50): sound 0x172/0x19 at the +0x10 point unless muted (+0x428), the +0x384 rig shakes
 * (020d17b8) and +0x94 = 400. The cue pulses at 0x330 (bit 0, 2) and 0x1650 (bit 1, 3). Once the
 * partner has no queued move the timer restarts, pose 0x16 plays and the node moves on to 020d0cb4. */

#include "nitro/types.h"
#include "game/enemy_common.h"

extern int Ov259_FaceTargetGap(int *node);
extern void Ov259_RefreshAim(int *node);
extern void Ov259_PlaySound(int actor, int id, int variant, void *at);
extern void Ov259_ReleaseRig(char *self);
extern void Ov259_MapHeldItemKindToAnim(int actor, int flag);
extern void Ov259_MirrorPartnerPose(int *node, int pose, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov259_RecoilTick(void);

void Ov259_SlamTick(int *node)
{
    int *state = (int *)node[1];
    int ground;

    state[0x1a] += *(int *)(node[0] + 0x2c);
    ground = Ov259_FaceTargetGap(node);
    Ov259_RefreshAim(node);
    if (ground <= 0) {
        state[5] = 0;
        state[7] = 0;
    }
    if (state[0x1a] >= 0xc38 && state[0x14] == 0) {
        if (*(int *)(*state + 0x428) == 0) {
            Ov259_PlaySound(*state, 0x172, 0x19, (void *)state[4]);
        }
        Ov259_ReleaseRig(*(char **)(*state + 0x384));
        state[0x25] = 0x190;
        state[0x14] = 1;
    }
    if ((*((u8 *)state + 0xac) & 1) == 0 && state[0x1a] >= 0x330) {
        *((u8 *)state + 0xac) |= 1;
        Ov259_MapHeldItemKindToAnim(*state, 2);
    }
    if ((*((u8 *)state + 0xac) & 2) == 0 && state[0x1a] >= 0x1650) {
        *((u8 *)state + 0xac) |= 2;
        Ov259_MapHeldItemKindToAnim(*state, 3);
    }
    if (*(u8 *)(state[1] + 0xad) != 0) {
        return;
    }
    state[0x1a] = 0;
    Ov107_PostTagUpdate((Actor *)(*state), 0x16, 0);
    Ov259_MirrorPartnerPose(node, 0x16, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov259_RecoilTick);
}
