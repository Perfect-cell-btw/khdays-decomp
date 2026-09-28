/* Volley-and-close tick of the ov283 actor: after the shared step (020ccb48, target distance) the
 * +0x48 clock runs up at the frame rate; with all 6 shots out (+0x68) it recovers (020cea48). Each
 * shot fires once the clock passes its step (x 0x88): a launch (020cc9e0) that finds no free helper
 * ends in 020ce97c, otherwise the shot counts. Once the +4 rig is idle: within 6.0 a d100 roll over 50
 * rerolls +0x34 (1.57 to 3.14; +0x7c = past 2.36, +0x3c cleared) for move 4, else move 2; farther
 * the +0x6c sequence plays (step 0: move 2 on a roll up to 20, else sound 8 with pose 10; step 1:
 * sound 9 with pose 11) and advances. */

#include "nitro/types.h"

typedef struct { int v[6]; } Steps6;

extern int Ov283_MeasureTargetGap(int *node);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern int Ov283_LaunchHelper(int *node);
extern int RandNextScaled(int bound);
extern int Rand16NextScaled(int bound);
extern void Ov283_PostItemUpdate(int owner, int id, int mode, int at);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov283_AiStep_QueueAction2OnAnimEnd(void);
extern void Ov283_TickBounce(void);
extern const Steps6 data_ov283_020cfb70;

void Ov283_VolleyCloseTick(int *node)
{
    int *state = (int *)node[1];
    Steps6 steps = data_ov283_020cfb70;
    int dist;
    int lo = 0;

    dist = Ov283_MeasureTargetGap(node);
    state[0x12] += *(int *)(node[0] + 0x2c);
    if ((unsigned int)state[0x1a] >= 6) {
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov283_AiStep_QueueAction2OnAnimEnd);
        return;
    }
    if (state[0x12] > steps.v[state[0x1a]] * 0x88) {
        if (Ov283_LaunchHelper(node) == 0) {
            SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov283_TickBounce);
            return;
        }
        state[0x1a]++;
    }
    if (*(u8 *)(state[1] + 0xad) != 0) {
        return;
    }
    if (dist < 0x6000) {
        if (RandNextScaled(0x65) + lo > 0x32) {
            state[0xd] = Rand16NextScaled(0x1922) + 0x1922;
            state[0x1f] = state[0xd] > 0x25b3;
            state[0xf] = 0;
            *(signed char *)(*state + 0x1c7) = 4;
            return;
        }
        *(signed char *)(*state + 0x1c7) = 2;
        return;
    }
    switch (state[0x1b]) {
    case 0:
        if (RandNextScaled(0x65) + lo <= 0x14) {
            *(signed char *)(*state + 0x1c7) = 2;
        } else {
            Ov283_PostItemUpdate(*state, 0x173, 8, state[2]);
            Ov107_PostTagUpdate(*state, 10, 0);
        }
        break;
    case 1:
        Ov283_PostItemUpdate(*state, 0x173, 9, state[2]);
        Ov107_PostTagUpdate(*state, 0xb, 0);
        break;
    }
    state[0x1b]++;
}
