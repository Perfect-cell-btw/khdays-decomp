/* Tick hook of the ov276 enemy: a hit-flagged actor (+0x1c4 bits 1/3) idling in sub-state 6
 * requests sub-state 2; outside sub-state 6 the +0x4a4 and +0x4b4 effect handles are finished
 * and cleared. The +0x3c0 transform (44 bytes) is copied into the +0x3b0 node and from there
 * into the +0x3ac item's node. The base tick always runs. */

#include "game/enemy_common.h"

struct Transform44 { int a[11]; };

struct Ov276Actor {
    char pad000[0x3ac];
    char **ppItem3ac;
    char *pNode3b0;
    char pad3b4[0xc];
    struct Transform44 xform3c0;
};

extern void TaskList_FinishByTag(int taskList, int handle);

void Ov276_TickHook(int actor)
{
    struct Ov276Actor *self = (struct Ov276Actor *)actor;

    if ((*(unsigned char *)(actor + 0x1c4) & 0xa) != 0) {
        if (*(signed char *)(actor + 0x1c7) == -1 && *(signed char *)(actor + 0x1c6) == 6) {
            ((signed char *)actor)[0x1c7] = 2;
        }
    }
    if (*(signed char *)(actor + 0x1c6) != 6) {
        if (*(int *)(actor + 0x4a4) != 0) {
            TaskList_FinishByTag(*(int *)(actor + 0x3c), *(int *)(actor + 0x4a4));
            *(int *)(actor + 0x4a4) = 0;
        }
        if (*(int *)(actor + 0x4b4) != 0) {
            TaskList_FinishByTag(*(int *)(actor + 0x3c), *(int *)(actor + 0x4b4));
            *(int *)(actor + 0x4b4) = 0;
        }
    }
    *(struct Transform44 *)(self->pNode3b0 + 0x10) = self->xform3c0;
    *(struct Transform44 *)(*self->ppItem3ac + 0x10) = *(struct Transform44 *)(self->pNode3b0 + 0x10);
    Ov107_AiState_PostTickBase((char *)actor);
}
