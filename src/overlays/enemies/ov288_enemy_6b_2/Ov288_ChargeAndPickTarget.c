/* Charge up until the timer saturates, then pick a random victim from the list at +0x398 and
 * commit to the attack. The timer at state[0xd] accumulates the owner's per-frame delta and is
 * clamped at 1.0; once there, the default target (+0x190) is armed, and if the count at +0x3b8
 * is positive a uniformly-random index into the list replaces it. The attack only starts when
 * either the range query fails or the distance it reports is over 0x800: bit 0 of the hw60 high
 * byte goes up and the action byte becomes 1.
 *
 * Matched byte-exact 2026-07-23, first compile. One of three byte-identical siblings. */

#include "game/enemy_common.h"

extern int RandNextScaled(int n);
extern void *List_First(void *list);
extern void *List_Next(void *list, void *node);
extern int Ov107_FindNearestObject(int obj, void *out);
extern int FX_Sqrt(int x);
extern void SetIndexedSlot(void *node, int idx, void *cb);

void Ov288_ChargeAndPickTarget(int *node) {
    int *owner = (int *)node[0];
    int *state = (int *)node[1];
    int d;

    state[0xd] = state[0xd] + *(int *)((int)owner + 0x2c);
    if (state[0xd] < 0x1000) {
        return;
    }
    state[0xd] = 0x1000;
    Ov107_MoveNodeAndRelayout((Actor *)state[0], (void *)(state[0] + 0x190));
    if (*(int *)(state[0] + 0x3b8) > 0) {
        int n = RandNextScaled(*(int *)(state[0] + 0x3b8));
        void *p = List_First((void *)(state[0] + 0x398));
        int i = 0;
        while (p != 0) {
            if (i >= n) {
                Ov107_MoveNodeAndRelayout((Actor *)state[0], p);
                break;
            }
            p = List_Next((void *)(state[0] + 0x398), p);
            i++;
        }
    }
    if (Ov107_FindNearestObject(state[0], &d) != 0) {
        if (FX_Sqrt(d) <= 0x800) {
            return;
        }
    }
    {
        unsigned short hw60 = *(unsigned short *)(state[0] + 0x60);
        *(unsigned short *)(state[0] + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 1) << 0x18) >> 0x10);
    }
    *(char *)(state[0] + 0x1c7) = 1;
    SetIndexedSlot(node, *(signed char *)((int)node + 0x20), 0);
}
