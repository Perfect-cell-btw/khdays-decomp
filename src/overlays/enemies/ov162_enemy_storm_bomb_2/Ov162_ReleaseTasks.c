/* Ov162_ReleaseTasks: release hook of the ov161 enemy (x2), variant of the matched ov131 sibling with a third task slot (+0x2c) and attachment (+0x3d4) finished outside sub-state 7. */

#include "game/enemy_common.h"

typedef struct { int w[11]; } SrtTransform;   /* 44 bytes, the node's SRT block */

extern void TaskList_FinishByTag(int owner, int handle);

void Ov162_ReleaseTasks(char *actor) {
    if (*(signed char *)(actor + 0x1c6) != 7) {
        if (*(int *)(*(char **)(actor + 0x3c4) + 0x14) != 0) {
            TaskList_FinishByTag(*(int *)(actor + 0x3c),
                          *(int *)(*(char **)(actor + 0x3c4) + 0x14));
            *(int *)(*(char **)(actor + 0x3c4) + 0x14) = 0;
        }
        if (*(int *)(*(char **)(actor + 0x3c4) + 0x24) != 0) {
            TaskList_FinishByTag(*(int *)(actor + 0x3c),
                          *(int *)(*(char **)(actor + 0x3c4) + 0x24));
            *(int *)(*(char **)(actor + 0x3c4) + 0x24) = 0;
        }
        if (*(int *)(*(char **)(actor + 0x3c4) + 0x2c) != 0) {
            TaskList_FinishByTag(*(int *)(actor + 0x3c),
                          *(int *)(*(char **)(actor + 0x3c4) + 0x2c));
            *(int *)(*(char **)(actor + 0x3c4) + 0x2c) = 0;
        }
        if (*(void **)(actor + 0x3d4) != 0) {
            Ov107_UnlinkNodeFromOwner(*(void **)(actor + 0x3d4));
            *(void **)(actor + 0x3d4) = 0;
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
    *(SrtTransform *)(**(char ***)(actor + 0x388) + 0x10) =
        *(SrtTransform *)(*(char **)(actor + 0x3c0) + 4);
    *(SrtTransform *)(*(char **)(actor + 0x38c) + 0x10) =
        *(SrtTransform *)(*(char **)(actor + 0x3c0) + 4);
    Ov107_AiState_PostTickBase(actor);
}
