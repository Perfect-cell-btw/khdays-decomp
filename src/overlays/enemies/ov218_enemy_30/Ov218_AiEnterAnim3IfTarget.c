/* Poll 020cc900: if it reports failure just dispatch, otherwise kick anim 3, clear +0x14/+0x40
 * and advance to 020cd404. */

#include "game/enemy_common.h"

extern int Ov218_DistanceToTarget(int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov218_ThrowTickAim(int);
void Ov218_AiEnterAnim3IfTarget(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov218_DistanceToTarget(param_1) < 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    } else {
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 3, 0);
        *(int *)(owner + 0x14) = 0;
        *(unsigned char *)(owner + 0x40) = 0;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov218_ThrowTickAim);
    }
}
