/* Kick anim 8, run 020cc8ec, arm the 020c5af8 timer, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov218_startAnim(int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int Ov218_ThrowEntryTick(int);
void Ov218_AiEnterAnim8WithUpdate(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 8, 0);
    Ov218_startAnim(*(int *)owner, 1);
    Ov107_BuildAndSendUpdate(*(int *)owner, 0x135, 7, *(int *)(owner + 8));
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov218_ThrowEntryTick);
}
