/* Kick anim 7 and the +0x428 sub-anim 3, notify 020cd148, clear +0x70/+0x7b, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov260_PlaySound(int, int, int);
extern int Ov260_LobTick(int);
void Ov260_AiEnterAnim7(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 7, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x428), 3, 0);
    Ov260_PlaySound(*(int *)owner, 0x12, *(int *)(owner + 0x10));
    *(int *)(owner + 0x70) = 0;
    *(signed char *)(owner + 0x7b) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov260_LobTick);
}
