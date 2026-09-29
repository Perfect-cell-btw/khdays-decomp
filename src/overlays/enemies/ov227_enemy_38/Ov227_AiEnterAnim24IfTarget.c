/* Spawn the child at +0x3e8; if it fails idle at state 2, else kick anim 0x18 and dispatch. */

#include "game/enemy_common.h"

extern int Ov107_FindNearestObject(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov227_AiAnim24To25(int);
void Ov227_AiEnterAnim24IfTarget(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int child = Ov107_FindNearestObject(*(int *)owner, 0);
    *(int *)(*(int *)owner + 0x3e8) = child;
    if (*(int *)(*(int *)owner + 0x3e8) == 0) {
        *(signed char *)(*(int *)owner + 0x1c7) = 2;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
    } else {
        Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x18, 0);
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov227_AiAnim24To25);
    }
}
