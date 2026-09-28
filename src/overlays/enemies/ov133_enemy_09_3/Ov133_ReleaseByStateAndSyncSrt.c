/* Post-tick: when the actor is flagged hurt outside its safe actions queues action 5; releases the
 * held tasks and the attachment that the current action no longer uses, copies the action
 * resource's transform to both models and runs the base post-tick. */

typedef struct { int w[11]; } SrtTransform;   /* 44 bytes, the node's SRT block */

extern void TaskList_FinishByTag(int owner, int handle);
extern void Ov107_UnlinkNodeFromOwner(void *attachment);
extern void Ov107_AiState_PostTickBase(void *actor);

void Ov133_ReleaseByStateAndSyncSrt(char *actor) {
    int state;

    if ((*(unsigned char *)(actor + 0x1c4) & 0xa) != 0) {
        state = *(signed char *)(actor + 0x1c6);
        if (state != 0 && state != 1 && state != 3 && state != 5) {
            *(signed char *)(actor + 0x1c7) = 5;
        }
    }

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
