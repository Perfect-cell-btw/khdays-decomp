/* Ov165_ReleaseTasks: release hook of the ov163 enemy (x3), variant of the matched ov131 sibling: the two item transforms are refreshed from the +0x3c0 item before the sub-state-dependent task finishes (no 0x1c4 guard here). */

#include "game/enemy_common.h"

typedef struct { int w[11]; } SrtTransform;   /* 44 bytes, the node's SRT block */

extern void TaskList_FinishByTag(int owner, int handle);

void Ov165_ReleaseTasks(char *actor) {
    *(SrtTransform *)(**(char ***)(actor + 0x388) + 0x10) =
        *(SrtTransform *)(*(char **)(actor + 0x3c0) + 4);
    *(SrtTransform *)(*(char **)(actor + 0x38c) + 0x10) =
        *(SrtTransform *)(*(char **)(actor + 0x3c0) + 4);
    if (*(signed char *)(actor + 0x1c6) != 7) {
        if (*(int *)(*(char **)(actor + 0x3c4) + 0x1c) != 0) {
            TaskList_FinishByTag(*(int *)(actor + 0x3c),
                          *(int *)(*(char **)(actor + 0x3c4) + 0x1c));
            *(int *)(*(char **)(actor + 0x3c4) + 0x1c) = 0;
        }
        if (*(int *)(*(char **)(actor + 0x3c4) + 0x24) != 0) {
            TaskList_FinishByTag(*(int *)(actor + 0x3c),
                          *(int *)(*(char **)(actor + 0x3c4) + 0x24));
            *(int *)(*(char **)(actor + 0x3c4) + 0x24) = 0;
        }
    }
    if (*(signed char *)(actor + 0x1c6) != 6) {
        if (*(int *)(*(char **)(actor + 0x3c4) + 4) != 0) {
            TaskList_FinishByTag(*(int *)(actor + 0x3c),
                          *(int *)(*(char **)(actor + 0x3c4) + 4));
            *(int *)(*(char **)(actor + 0x3c4) + 4) = 0;
        }
        if (*(void **)(actor + 0x3d0) != 0) {
            Ov107_UnlinkNodeFromOwner(*(void **)(actor + 0x3d0));
            *(void **)(actor + 0x3d0) = 0;
        }
    }
    Ov107_AiState_PostTickBase(actor);
}
