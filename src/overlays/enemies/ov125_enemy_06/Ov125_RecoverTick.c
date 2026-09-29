/* Recover tick of the ov125 enemy: the +0x2c timer accumulates the owner's +0x2c rate; once it
 * passes 0x2000 (once, latched in bit 1 of +0x34) the data_ov125_020d03cc[2..3] message pair is
 * sent to the +0x24 hook (arg 4) and the +0x3c counter cleared. The +0xc speed drops to 0x200
 * while the +0x13c height is under 0x4000 and the look-at at +0x68 is rebuilt from the +4
 * target's +0x74 pose, the +0x24 anchor and data_02042264. Past 0x5000 the [0..1] pair is sent,
 * action 5/0 fired and the next state registered; between 0x800 and that, the same happens as
 * soon as the +0x390 aim node reports idle. */

#include "game/enemy_common.h"

struct b2 { unsigned char b0 : 1, b1 : 1; };

extern void Mtx33_LookAt(void *out, void *a, int b, void *c);
extern void Quat_FromMtx33(void *a, void *b);
extern void SetIndexedSlot(int self, int idx, void *cb);
extern int Ov125_IsField34Nibble1(int node);
extern unsigned short data_ov125_020d03cc[];
extern int data_02042264;
extern void Ov125_AiQueue2AndRollTimer(void);

void Ov125_RecoverTick(int *self) {
    int owner = *(int *)self[1];
    int *state = (int *)self[1];
    unsigned short pairA[2];
    unsigned short pairB[2];
    int buf[9];
    unsigned short *pp;
    void (*cb)();

    state[0xb] += *(int *)(self[0] + 0x2c);
    if (((struct b2 *)(state + 0xd))->b1 == 0 && state[0xb] >= 0x2000) {
        pp = pairA;
        pp[1] = data_ov125_020d03cc[3];
        pp[0] = data_ov125_020d03cc[2];
        cb = *(void (**)())(*state + 0x24);
        if (cb != 0) cb(*state, pp, 4);
        state[0xf] = 0;
        *(unsigned char *)(state + 0xd) |= 2;
    }
    if (*(int *)(owner + 0x13c) < 0x4000) {
        state[3] = 0x200;
    }
    Mtx33_LookAt(buf, (void *)(state[1] + 0x74), state[9], &data_02042264);
    Quat_FromMtx33(state + 0x1a, buf);
    if (state[0xb] >= 0x5000) {
        pp = pairB;
        pp[1] = data_ov125_020d03cc[1];
        pp[0] = data_ov125_020d03cc[0];
        cb = *(void (**)())(*state + 0x24);
        if (cb != 0) cb(*state, pp, 4);
        Ov107_PostTagUpdate((Actor *)(*state), 5, 0);
        SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), Ov125_AiQueue2AndRollTimer);
        return;
    }
    if (state[0xb] < 0x800) {
        return;
    }
    if (Ov125_IsField34Nibble1(*(int *)(*state + 0x390)) != 0) {
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 5, 0);
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), Ov125_AiQueue2AndRollTimer);
}
